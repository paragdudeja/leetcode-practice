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
        curr.push_back(root->val);
        if(!root->left && !root->right) { // Leaf node
            string path = to_string(curr[0]);
            for(int i = 1; i < curr.size(); i++) {
                path += "->" + to_string(curr[i]);
            }
            res.push_back(path);
        }
        helper(root->left, curr, res);
        helper(root->right, curr, res);
        curr.pop_back();
        
    }
};