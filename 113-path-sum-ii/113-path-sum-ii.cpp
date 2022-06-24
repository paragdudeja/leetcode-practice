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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        helper(root, targetSum, path, result);
        return result;
    }
    
    void helper(TreeNode *root, int target, vector<int> &path, vector<vector<int>> &result) {
        if(!root) return;
        
        path.push_back(root->val);
        if(!root->left && !root->right && root->val == target)
            result.push_back(path);
        
        helper(root->left, target - root->val, path, result);
        helper(root->right, target - root->val, path, result);
        
        path.pop_back();
    }
};