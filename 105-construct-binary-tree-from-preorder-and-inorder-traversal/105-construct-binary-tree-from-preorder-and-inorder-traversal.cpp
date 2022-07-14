/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        int n = preorder.size();
        for(int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        return buildTree(preorder, 0, n - 1, inorder, 0, n - 1, inMap);
    }
    
    TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;
    
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};