/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root == p || root == q) return root;
        
        TreeNode *parent1 = lowestCommonAncestor(root->left, p, q);
        TreeNode *parent2 = lowestCommonAncestor(root->right, p, q);
        
        if(parent1 && parent2) return root;
        return parent1 ? parent1 : parent2;
    }
};