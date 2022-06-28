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
    int longestZigZag(TreeNode* root) {
        int longest = 0;
        helper(root->left, root, 1, longest);
        helper(root->right, root, 1, longest);
        return longest;
    }
    
    void helper(TreeNode *root, TreeNode *p, int curr, int &longest) {
        if(!root) return;
        
        longest = max(curr, longest);
        if(p->left == root) {
            helper(root->left, root, 1, longest);
            helper(root->right, root, curr+1, longest);
        }
        else {
            helper(root->left, root, curr+1, longest);
            helper(root->right, root, 1, longest);
        }
    }
};