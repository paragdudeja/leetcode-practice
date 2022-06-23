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
    int goodNodes(TreeNode* root) {
        int count = 0, val = root->val;
        dfs(root, count, val);
        return count;
    }
    
    void dfs(TreeNode *root, int &count, int min_val) {
        if(!root) return;
        
        if(root->val >= min_val) count++;
        dfs(root->left, count, max(root->val, min_val));
        dfs(root->right, count, max(root->val, min_val));
    }
};