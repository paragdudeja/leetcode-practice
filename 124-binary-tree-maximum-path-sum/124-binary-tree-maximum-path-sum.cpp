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
        if (root == NULL) return 0;
    
        int leftSum = max(0, helper(root->left, ans));
        int rightSum = max(0, helper(root->right, ans));
        ans = max(ans, root->val + leftSum + rightSum);
        return root->val + max(leftSum, rightSum);
    }
};