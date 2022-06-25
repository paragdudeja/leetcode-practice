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
    int rob(TreeNode* root) {
        if(!root) return 0;
        unordered_map<TreeNode*, int> dp;
        return helper(root, dp);
    }
    
    int helper(TreeNode *root, unordered_map<TreeNode*, int> &dp) {
        if(!root) return 0;
        if(dp.find(root) != dp.end())
            return dp[root];
        
        // Pick
        int pick = root->val;
        if(root->left)
            pick += helper(root->left->left, dp) + helper(root->left->right, dp);
        if(root->right)
            pick += helper(root->right->left, dp) + helper(root->right->right, dp);
        
        // Not Pick
        int notPick = helper(root->left, dp) + helper(root->right, dp);
        return dp[root] = max(pick, notPick);
    }
};