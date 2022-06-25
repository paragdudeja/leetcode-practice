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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + pathSumIncludes(root, targetSum);
    }
    
    int pathSumIncludes(TreeNode* root, long long targetSum) {
        if(!root) return 0;
        int count = 0;
        if(targetSum == root->val) count++;
        count += pathSumIncludes(root->left, targetSum - root->val) + pathSumIncludes(root->right, targetSum - root->val);
        return count;
    }
};