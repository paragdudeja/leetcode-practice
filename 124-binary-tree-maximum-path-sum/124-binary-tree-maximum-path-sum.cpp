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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
    
    int helper(TreeNode* root, int &ans) {
        if(!root) return 0;
        
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        
        int currPathSum = root->val + max(left, 0) + max(right, 0);
        ans = max(ans, currPathSum);
        
        return root->val + max({left, right, 0});
    }
};