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
    // TC : O(Log^2 N) or O( (Log N)^2 )
    // SC : O(Log N) (recursion stack)
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);
        
        if(leftHeight == rightHeight) {
            return (1 << leftHeight) - 1; // pow(2, leftHeight) - 1;
        }
        else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
    
    int getLeftHeight(TreeNode *root) {
        int height = 1;
        while(root->left) {
            root = root->left;
            ++height;
        }
        return height;
    }
    
    int getRightHeight(TreeNode *root) {
        int height = 1;
        while(root->right) {
            root = root->right;
            ++height;
        }
        return height;
    }
    
    /*
    TC : O(N)
    SC : O(Log N) / O(H) here height is Log N
    int countNodes(TreeNode* root) {
        return root ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
    }
    */
    
};