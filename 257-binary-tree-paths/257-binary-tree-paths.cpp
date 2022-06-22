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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> current;
        vector<string> result;
        helper(root, current, result);
        return result;
    }
    
    void helper(TreeNode *root, vector<int> &curr, vector<string> &res) {
        if(!root) return;
        // curr.push_back(root->val);
        if(!root->left && !root->right) { // Leaf node
            string path;
            for(int i = 0; i < curr.size(); i++) {
                path += to_string(curr[i]) + "->";
            }
            path += to_string(root->val);
            res.push_back(path);
            return;
        }
        curr.push_back(root->val);
        helper(root->left, curr, res);
        helper(root->right, curr, res);
        curr.pop_back();
        
    }
};