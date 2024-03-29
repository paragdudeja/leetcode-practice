class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp1(target+1, 0);
        
        dp1[0] = 1;
        
        for(int i = 1; i <= n; ++i) {
            vector<int> dp2(target + 1);
            for(int t = 1; t <= target; ++t) {
                for(int num = 1; num <= k; ++num) {
                    if(t >= num) {
                        dp2[t] = (dp2[t] + dp1[t - num]) % 1000000007; 
                    } 
                }
            }
            dp1 = dp2;
        }
        return dp1[target];
    }
    
    /*
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; ++i) {
            for(int t = 1; t <= target; ++t) {
                for(int num = 1; num <= k; ++num) {
                    if(t >= num) {
                        dp[i][t] = (dp[i][t] + dp[i-1][t - num]) % 1000000007; 
                    } 
                }
            }
        }
        return dp[n][target];
    }
    */
    
    /*
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
    */
};