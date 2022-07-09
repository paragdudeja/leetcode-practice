class Solution {
public:
    // TC: O(N)
    // SC  O(N)
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[1] = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i+1] = max(dp[i], nums[i] + dp[i-1]);
        }
        return dp[n];
    }
};