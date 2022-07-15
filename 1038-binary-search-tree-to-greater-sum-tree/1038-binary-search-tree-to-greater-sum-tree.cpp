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
    int rollingSum(TreeNode* r, int sum = 0) {
        if (r == nullptr) return sum;
        r->val += rollingSum(r->right, sum);
        return rollingSum(r->left, r->val);
    }
    
    TreeNode* bstToGst(TreeNode* r) {
        rollingSum(r);
        return r;
    }
    
    /*
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }
    
    void helper(TreeNode *root, int &sum) {
        if(!root) return;
        helper(root->right, sum);
        root->val += sum;
        sum = root->val;
        helper(root->left, sum);
    }
    */
};