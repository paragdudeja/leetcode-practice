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
private:
    bool buildPath(TreeNode *root, int val, vector<TreeNode*> &path) {
        if(!root) return false;
        path.push_back(root);
        if(root->val == val) return true;
        if(buildPath(root->left, val, path) || buildPath(root->right, val, path)) return true;
        path.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<TreeNode*> path1, path2;
        buildPath(root, startValue, path1);
        buildPath(root, destValue, path2);
        /*
        for(auto &node: path1) {
            cout << node->val << ' ';
        }
        cout << endl;
        for(auto &node: path2) {
            cout << node->val << ' ';
        }
        */
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
};