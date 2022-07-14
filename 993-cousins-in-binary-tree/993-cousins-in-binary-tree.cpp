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

struct NodeStatus{
    TreeNode *parent;
    int depth;
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        auto statusX = getStatus(root, 0, x, NULL);
        auto statusY = getStatus(root, 0, y, NULL);
        return statusX.depth == statusY.depth && statusX.parent != statusY.parent;
    }
    
    NodeStatus getStatus(TreeNode *root, int current_depth, int x, TreeNode *parent) {
        if(!root) return {NULL, -1};
        if(root->val == x) {
            return {parent, current_depth};
        }
        auto left = getStatus(root->left, current_depth + 1, x, root);
        if(left.depth != -1) {
            return left;
        }
        auto right = getStatus(root->right, current_depth + 1, x, root);
        if(right.depth != -1) {
            return right;
        }
        return {NULL, -1};
    }
};