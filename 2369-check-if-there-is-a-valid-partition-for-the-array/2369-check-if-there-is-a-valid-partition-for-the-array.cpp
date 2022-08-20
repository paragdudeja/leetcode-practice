class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> dp(n+1);
        dp[n] = true;
        dp[n-2] = nums[n-2] == nums[n-1];
        for(int index = n-3; index >= 0; index--) {
            if(nums[index] == nums[index+1]) {
                dp[index] = dp[index] or dp[index+2];
            }
            if(nums[index]==nums[index+1] && nums[index]==nums[index+2]) {
                dp[index] = dp[index] or dp[index+3];
            }
            else if(nums[index]+1==nums[index+1] && nums[index]+2==nums[index+2]) {
                dp[index] = dp[index] or dp[index+3];
            }
        }
        return dp[0];
    }
    
    /*
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, -1);
        return solve(0, nums, dp);
    }
    
    bool solve(int index, vector<int> &nums, vector<int> &dp) {
        if(index == nums.size()) return true;
        
        if(dp[index] != -1) return dp[index];
        if(index+1 >= nums.size()) return dp[index] = false;
        if(nums[index] == nums[index+1]) {
            if(solve(index+2, nums, dp))
                return dp[index] = true;
        }
        
        if(index+2 >= nums.size()) return dp[index] = false;
        if(nums[index] == nums[index+1] && nums[index+1]==nums[index+2]) {
            if(solve(index+3, nums, dp))
                return dp[index] = true;
        }
        
        if(nums[index+1]==nums[index]+1 && nums[index+2]==nums[index]+2) {
            if(solve(index+3, nums, dp))
                return dp[index] = true;
        }
        
        return dp[index] = false;
    }
    */
};