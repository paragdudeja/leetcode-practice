class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int oneStep = 1, twoStep = 1;
        for(int i = 2; i <= n; i++) {
            int currentWays = oneStep + twoStep;
            twoStep = oneStep;
            oneStep = currentWays;
        }
        return oneStep;
    }
    
    /*
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
    */
};