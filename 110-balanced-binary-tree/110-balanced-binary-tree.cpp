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

struct BalanceStatus {
    bool balanced;
    int height;
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return helper(root).balanced;
    }
    
    BalanceStatus helper(TreeNode *root) {
        if(!root) {
            return {true, 0};
        }
        
        BalanceStatus left = helper(root->left);
        if(!left.balanced)
            return {false, 0};
        
        BalanceStatus right = helper(root->right);
        if(!right.balanced)
            return {false, 0};
        
        bool balanced = abs(left.height - right.height) <= 1;
        int height = 1 + max(left.height, right.height);
        
        return {balanced, height};
    }
};