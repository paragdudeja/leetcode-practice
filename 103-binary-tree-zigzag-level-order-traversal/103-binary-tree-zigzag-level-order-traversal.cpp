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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        
        queue<TreeNode*> q;
        stack<int> reversed;
        bool is_reverse = false;
        
        q.push(root);
        
        while(!q.empty()) {
            int count = q.size();
            vector<int> level;
            
            for(int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(is_reverse)
                    reversed.push(node->val);
                else
                    level.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            while(!reversed.empty()) {
                level.push_back(reversed.top());
                reversed.pop();
            }
            is_reverse = !is_reverse;
            result.push_back(level);
        }
        return result;
    }
};