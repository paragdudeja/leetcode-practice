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
    // Iterative
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) {
            return ans;
        }
        
        stack<TreeNode*> st;
        TreeNode *curr = root;
        while(!st.empty() || curr) {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                curr = st.top();
                st.pop();
                
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return ans;
    }
    
    /*
    // Recursive
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    
    void inorder(TreeNode *root, vector<int> &ans) {
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    */
};