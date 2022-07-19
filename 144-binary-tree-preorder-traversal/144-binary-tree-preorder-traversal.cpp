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
    
    // Morris preorder
    // TC : O(N)
    // SC : O(1)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *curr = root;
        while(curr) {
            if(curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode *prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if(prev->right == NULL) {
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
    
    /*
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        
        TreeNode *curr = root;
        while(!st.empty() || curr) {
            if(curr) {
                ans.push_back(curr->val);
                if(curr->right) st.push(curr->right);
                curr = curr->left;
            }
            else {
                curr = st.top();
                st.pop();
                // ans.push_back(curr->val);
                // curr = curr->right;
            }
        }
        return ans;
    }
    */
    
    
    /*
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    
    void preorder(TreeNode *root, vector<int> &ans) {
        if(!root) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    */
};