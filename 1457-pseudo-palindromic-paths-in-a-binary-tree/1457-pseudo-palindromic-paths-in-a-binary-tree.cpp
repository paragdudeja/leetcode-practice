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
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        vector<int> digits(10);
        helper(root, digits, count);
        return count;
    }
    
    void helper(TreeNode *root, vector<int> &digits, int &count) {
        if(!root) return;
        digits[root->val]++;
        if(!root->left && !root->right && checkPalindrome(digits)) ++count;
        helper(root->left, digits, count);
        helper(root->right, digits, count);
        digits[root->val]--;
    }
    
    bool checkPalindrome(vector<int> &digits) { 
        int odd_count = 0;
        for(int i = 1; i <= 9; ++i) {
            if(digits[i]&1) {
                odd_count++;
            }
        }
        return odd_count <= 1;
    }
};