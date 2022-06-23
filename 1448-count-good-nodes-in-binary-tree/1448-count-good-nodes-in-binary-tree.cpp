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
    int goodNodes(TreeNode* root, int min_val = -100000) {
        if(!root) return 0;
        int count = 0;
        if(root->val >= min_val) count = 1;
        min_val = max(min_val, root->val);
        count += goodNodes(root->left, min_val) + goodNodes(root->right, min_val);
        return count;
    }
    
};