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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxWidth = 0;
        
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            int low = q.front().second, high = q.back().second;
            maxWidth = max(maxWidth, high - low + 1);
            
            int count = q.size();
            for(int i = 0; i < count; i++) {
                auto data = q.front();
                q.pop();
                
                auto node = data.first;
                unsigned int pos = data.second - low;
                
                if(node->left) q.push({node->left, pos*2 + 1});
                if(node->right) q.push({node->right, pos*2 + 2});
            }
        }
        return maxWidth;
    }
};