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

struct NodeStatus {
    int sum;
    bool isBST;
    int maxLeft;
    int minRight;
};

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
    
    NodeStatus helper(TreeNode *root, int &ans) {
        if(!root) return {0, true, INT_MIN, INT_MAX};
        
        NodeStatus left = helper(root->left, ans);
        NodeStatus right = helper(root->right, ans);
        
        int sum = root->val + left.sum + right.sum;
        bool isBST = left.isBST && right.isBST && root->val > left.maxLeft  && root->val < right.minRight;
        if(isBST) ans = max(ans, sum);
        int maxLeft = max(root->val, right.maxLeft);
        int minRight = min(root->val, left.minRight);
        
        return {sum, isBST, maxLeft, minRight};
    }
};