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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int> > > mp;    
        solve(root, 0, 0, mp);
        
        vector<vector<int>> result;
        for(auto it1: mp) {
            vector<int> level;
            for(auto it2: it1.second) {
                for(auto it3: it2.second) {
                    level.push_back(it3);
                }
            }
            result.push_back(level);
        }
        return result;
    }
    
    void solve(TreeNode *root, int row, int col, map<int, map<int, multiset<int> > > &mp) {
        if(!root) return;
        mp[col][row].insert(root->val);
        solve(root->left, row+1, col-1, mp);
        solve(root->right, row+1, col+1, mp);
    }
};