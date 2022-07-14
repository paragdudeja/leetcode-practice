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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = 1, rightHeight = 1;
        TreeNode *curr = root;
        while(curr->left) {
            curr = curr->left;
            leftHeight++;
        }
        curr = root;
        while(curr->right) {
            curr = curr->right;
            rightHeight++;
        }
        if(leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }
        else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
    
    /*
    TC : O(N)
    SC : O(Log N) / O(H) here height is Log N
    int countNodes(TreeNode* root) {
        return root ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
    }
    */
    
};