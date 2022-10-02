class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(31, vector<int>(1001, -1));
        return solve(n, k, target, dp);
    }
    
    int solve(int n, int k, int target, vector<vector<int>> &dp) {
        if(target < 0) return 0;
        if(n == 0) return target == 0;
        
        if(dp[n][target] != -1) return dp[n][target];
        
        int ans = 0;
        for(int i = 1; i <= k; ++i) {
            ans = (ans + solve(n-1, k, target - i, dp))%1000000007;
        }
        return dp[n][target] = ans;
    }
};