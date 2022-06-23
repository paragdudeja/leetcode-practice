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
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool validate(TreeNode* root, long long min_value, long long max_value) {
        if(!root) return true;
        
        return root->val > min_value && root->val < max_value 
            && validate(root->left, min_value, root->val) 
            && validate(root->right, root->val, max_value);
    }
};