class Solution {
public:
    int integerBreak(int n) {
       vector<int> dp(n+1);
       dp[1] = 1;
       for(int i = 2; i <= n; i ++) {
           for(int j = 1; j < i; j ++) {
               dp[i] = max(dp[i], max(j,dp[j]) * max(i - j, dp[i - j]));
           }
       }
       return dp[n];

    }
    /*
    int integerBreak(int n) {
        if(n <= 2) return 1;
        if(n == 3) return 2;
        int prod = 1;
        while(n > 4) {
            n -= 3;
            prod *= 3;
        }
        return prod * n;
    }
    */
};