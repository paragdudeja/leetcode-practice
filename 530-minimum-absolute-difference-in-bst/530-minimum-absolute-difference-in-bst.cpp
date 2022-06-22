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
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        TreeNode* prev = NULL;
        help(root, min_diff, prev);
        return min_diff;
    }
    void help(TreeNode* root, int& min_diff, TreeNode* &prev){
        if(root->left) 
            help(root->left, min_diff, prev);
        if(prev)
            min_diff = min(min_diff, abs(prev->val - root->val));
        prev = root;
        if(root->right) help(root->right, min_diff, prev);
    }
    
    
    /*
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        vector<int> trav;
        helper_inorder(root, trav);
        for(int i = 1; i < trav.size(); i++)
            ans = min(ans, trav[i] - trav[i-1]);
        return ans;
    }
    
    void helper_inorder(TreeNode *root, vector<int> &trav) {
        if(!root) return;
        
        helper_inorder(root->left, trav);
        trav.push_back(root->val);
        helper_inorder(root->right, trav);
    }
    
    */
};