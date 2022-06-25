/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> parent;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            
            if(node->left) {
                parent[node->left->val] = node;
                q.push(node->left);
            }
            
            if(node->right) {
                parent[node->right->val] = node;
                q.push(node->right);
            }
        }
        
        //  Now queue is empty, so we can reuse it
        unordered_set<int> visited;
        q.push(target);
        visited.insert(target->val);
        
        while(!q.empty() && k-- > 0) {
            int count = q.size();
            
            for(int i = 0; i < count; i++) {
                auto node = q.front();
                q.pop();
                
                if(node->left && visited.count(node->left->val) == 0) {
                    visited.insert(node->left->val);
                    q.push(node->left);
                }
                
                if(node->right && visited.count(node->right->val) == 0) {
                    visited.insert(node->right->val);
                    q.push(node->right);
                }
                
                if(parent.count(node->val) == 1 && visited.count(parent[node->val]->val) == 0) {
                    visited.insert(parent[node->val]->val);
                    q.push(parent[node->val]);
                }
            }
        }
        
        vector<int> result;
        while(!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
};