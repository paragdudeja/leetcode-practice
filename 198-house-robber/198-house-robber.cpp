class Solution {
public:
    // TC: O(N)
    // SC  O(1)
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = 0, prev2 = 0, current = 0;
        for(int i = 0; i < n; i++) {
            current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
    /*
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
    */
};