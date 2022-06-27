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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        unordered_map<int, int> idx;
        int n = inorder.size();
        
        for(int i = 0; i < n; i++)
            idx[inorder[i]] = i;
        
        int currentIdx = 0;
        return makeTree(0, n-1, currentIdx, idx, inorder, preorder);
    }
    
    TreeNode* makeTree(int left, int right, int &currentIdx, unordered_map<int, int> &idx, vector<int> &inorder, vector<int> &preorder) {
        if(left > right) return nullptr;
        
        int pivot = idx[preorder[currentIdx]];
        currentIdx++;
        TreeNode *root = new TreeNode(inorder[pivot]);
        
        root->left = makeTree(left, pivot-1, currentIdx, idx, inorder, preorder);
        root->right = makeTree(pivot+1, right, currentIdx, idx, inorder, preorder);
        
        return root;
    }
};