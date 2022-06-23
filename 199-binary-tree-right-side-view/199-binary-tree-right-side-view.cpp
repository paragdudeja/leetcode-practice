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
    // Iterative/BFS
    
    // TC : O(N)
    // SC : O(N)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int count = q.size();
            ans.push_back(q.back()->val);
            
            for(int i = 0; i < count; i++) {
                TreeNode *node = q.front();
                q.pop();
                
                if(node->left) {
                    q.push(node->left);
                }
                
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
    
    /*
    // Recursive/DFS
    
    // TC : O(N)
    // SC : O(height)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
    
    void dfs(TreeNode *root, int level, vector<int> &res) {
        if(!root) return;
        
        if(level == res.size()) 
            res.push_back(root->val);
        
        dfs(root->right, level + 1, res);
        dfs(root->left, level + 1, res);        
    }
    */
};