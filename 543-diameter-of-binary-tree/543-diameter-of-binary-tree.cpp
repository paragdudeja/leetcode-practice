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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        getHeight(root, ans);
        return ans;
    }
    
    int getHeight(TreeNode *root, int &ans) {
        if(root == nullptr) return 0;
        int leftHeight = getHeight(root->left, ans);
        int rightHeight = getHeight(root->right, ans);
        
        ans = max(ans, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
    
};