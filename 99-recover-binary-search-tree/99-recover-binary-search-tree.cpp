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
    // TC : O(N)
    // SC : O(height) / O(1) (iterative)
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        helper(root, prev, first, second);
        swap(first->val, second->val);
    }
    
    void helper(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second) {
        if(!root) return;
        helper(root->left, prev, first, second);
        if(prev && root->val < prev->val) {
            if(!first) first = prev;
            second = root;
        }
        prev = root;
        helper(root->right, prev, first, second);
    }
    
    /*
    // TC : O(N)
    // SC : O(N) for vector
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);
        TreeNode *first=NULL, *second=NULL, *prev=NULL;
        for(int i=0; i<v.size(); i++) {
            if(prev && v[i]->val < prev->val){
                if(!first) first = prev;
                second = v[i];
            }
            prev = v[i];
        }
        swap(first->val, second->val);
    }
    
    void inorder(TreeNode *root, vector<TreeNode*> &v) {
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    */
};