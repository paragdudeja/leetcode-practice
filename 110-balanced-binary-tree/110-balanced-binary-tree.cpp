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
    bool isBalanced;
    int height;
    BalanceStatus(bool isBalanced, int height) : isBalanced(isBalanced), height(height) {}    
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return helper(root).isBalanced;
    }
    
    BalanceStatus helper(TreeNode *root) {
        if(!root) {
            return BalanceStatus(true, 0);
        }
        
        BalanceStatus left = helper(root->left);
        BalanceStatus right = helper(root->right);
        
        bool isBalanced = left.isBalanced && right.isBalanced && abs(left.height - right.height) <= 1;
        int height = 1 + max(left.height, right.height);
        
        return BalanceStatus(isBalanced, height);
    }
};