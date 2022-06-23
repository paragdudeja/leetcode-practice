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
    vector<TreeNode*> generateTrees(int n) {
        return help_generate(1, n);
    }
    
    vector<TreeNode*> help_generate(int low, int high) {
        if(low > high)
            return {nullptr};
        
        
        vector<TreeNode*> trees;
        for(int node = low; node <= high; node++) {
            vector<TreeNode*> leftTree = help_generate(low, node - 1);
            vector<TreeNode*> rightTree = help_generate(node + 1, high);
            
            for(auto leftRoot: leftTree) {
                for(auto rightRoot: rightTree) {
                    TreeNode *root = new TreeNode(node);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    trees.push_back(root);
                }
            }    
        }
        
        
        return trees;
    }
};