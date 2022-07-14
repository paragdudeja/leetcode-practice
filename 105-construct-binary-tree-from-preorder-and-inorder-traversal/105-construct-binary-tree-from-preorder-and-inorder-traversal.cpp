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
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        int current = 0;
        return makeTree(0, n-1, current, preorder, inorder, mp);
    }
    
    TreeNode *makeTree(int low, int high, int &current, vector<int> &preorder, vector<int> &inorder, 
                      unordered_map<int, int> &mp) {
        if(low > high) return nullptr;
        TreeNode *root = new TreeNode(preorder[current]);
        int idx = mp[preorder[current]];
        current++;
        
        root->left = makeTree(low, idx-1, current, preorder, inorder, mp);
        root->right = makeTree(idx+1, high, current, preorder, inorder, mp);
        
        return root;
    }
};