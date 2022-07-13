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
    bool find(TreeNode* n, int val, string &path) {
        if (n->val == val)
            return true;
        if (n->left && find(n->left, val, path))
            path.push_back('L');
        else if (n->right && find(n->right, val, path))
            path.push_back('R');
        return !path.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s_p, d_p;
        find(root, startValue, s_p);
        find(root, destValue, d_p);
        while (!s_p.empty() && !d_p.empty() && s_p.back() == d_p.back()) {
            s_p.pop_back();
            d_p.pop_back();
        }
        return string(s_p.size(), 'U') + string(rbegin(d_p), rend(d_p));
    }
    /*
    bool buildPath(TreeNode *root, int val, vector<TreeNode*> &path) {
        if(!root) return false;
        path.push_back(root);
        if(root->val == val) return true;
        if(buildPath(root->left, val, path) || buildPath(root->right, val, path)) return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<TreeNode*> path1, path2;
        buildPath(root, startValue, path1);
        buildPath(root, destValue, path2);
        // for(auto &node: path1) {
        //     cout << node->val << ' ';
        // }
        // cout << endl;
        // for(auto &node: path2) {
        //     cout << node->val << ' ';
        // }
        int i = 0;
        for(i = 0; i+1 < path1.size() && i+1 < path2.size(); i++) {
            if(path1[i+1]->val != path2[i+1]->val) {
                break;
            }
        }
        
        string ans;
        for(int j = i; j + 1 < path1.size(); j++) {
            ans.push_back('U');
        }
        for(int j = i; j + 1 < path2.size(); j++) {
            if(path2[j+1] == path2[j]->right) {
                ans.push_back('R');
            }
            else {
                ans.push_back('L');
            }
        }
        
        return ans;
    }
    */
};