class Solution {
public:
    int integerBreak(int n) {
       vector<int> dp(n+2, 0);
        dp[2] = 2;
        dp[3] = 3;
        if(n <= 3) return dp[n]-1;
        for(int i = 4; i <= n; i++){
            for(int j = 1; j < i; j++)
                dp[i] = max(dp[i], dp[j]*(i-j)); 
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