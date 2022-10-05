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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        else {
            queue<TreeNode*> q;
            q.push(root);
            while(--depth > 1) {
                int count = q.size();
                for(int i = 0; i < count; ++i) {
                    TreeNode *node = q.front();
                    q.pop();
                    
                    if(node->left)  {
                        q.push(node->left);
                    }
                    
                    if(node->right) {
                        q.push(node->right);
                    }
                }
            }
            
            while(!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                
                node->left = new TreeNode(val, node->left, nullptr);
                node->right = new TreeNode(val, nullptr, node->right);                 
            }
            return root;
        }
    }
};