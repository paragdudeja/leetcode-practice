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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // return makeBST(nums, 0, nums.size() - 1); 
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1)
        {
            return new TreeNode(nums[0]);
        }
        
        int middle = nums.size()/2;
        TreeNode* root = new TreeNode(nums[middle]);
        
        vector<int> leftInts(nums.begin(), nums.begin()+middle);
        vector<int> rightInts(nums.begin()+middle+1, nums.end());
        
        root->left = sortedArrayToBST(leftInts);
        root->right = sortedArrayToBST(rightInts);
        
        return root;
    }
    
    /*
    TreeNode *makeBST(vector<int> &nums, int left, int right) {
        if(left > right)
            return NULL;
        int mid = left + (right - left)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = makeBST(nums, left, mid - 1);
        root->right = makeBST(nums, mid + 1, right);
        return root;
    }
    */
};