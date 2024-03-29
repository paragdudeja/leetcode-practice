class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, INT_MIN));
        return solve(0, 0, nums.size()-1, nums, multipliers, dp);
    }
    
    int solve(int idx, int start, int end, vector<int> &nums, vector<int> &multipliers, vector<vector<int>> &dp) {
        if(idx == multipliers.size()) return 0;
        
        if(dp[start][idx] != INT_MIN) return dp[start][idx];
        
        int startPick = multipliers[idx]*nums[start] + solve(idx+1, start+1, end, nums, multipliers, dp);
        int endPick = multipliers[idx]*nums[end] + solve(idx+1, start, end-1, nums, multipliers, dp);
        
        return dp[start][idx] =  max(startPick, endPick);
    }
};