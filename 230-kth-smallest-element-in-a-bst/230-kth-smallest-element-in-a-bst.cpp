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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = nullptr;
        helper(root, k, node);
        return node->val;
    }
    
    void helper(TreeNode *root, int &k, TreeNode* &node) {
        if(!root) return;
        helper(root->left, k, node);
        
        k--;
        if(k == 0){
            node = root;
            return;
        }
        helper(root->right, k, node);
    }
    
    /*
    // TC : O(N)
    // SC : O(N)
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        return v[k-1];
    }
    
    void inorder(TreeNode* root, vector<int> &v) {
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    */
};