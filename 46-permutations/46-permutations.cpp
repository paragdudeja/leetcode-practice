class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(0, nums, result);
        return result;
    }
    
    void helper(int i, vector<int> &nums, vector<vector<int>> &res) {
        if(i == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for(int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            helper(i + 1, nums, res);
            swap(nums[i], nums[j]);
        }
    }
    
};