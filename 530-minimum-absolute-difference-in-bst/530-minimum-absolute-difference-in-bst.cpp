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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        vector<int> trav;
        helper_inorder(root, trav);
        for(int i = 1; i < trav.size(); i++)
            ans = min(ans, trav[i] - trav[i-1]);
        return ans;
    }
    
    void helper_inorder(TreeNode *root, vector<int> &trav) {
        if(!root) return;
        
        helper_inorder(root->left, trav);
        trav.push_back(root->val);
        helper_inorder(root->right, trav);
    }
};