class Solution {
public:
    int numTilings(int n) {
        if(n <= 2) return n;
        const int mod = 1e9 + 7;
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4; i <= n; i++) {
            dp[i] = ((2 * dp[i-1])%mod + (dp[i-3])%mod)%mod;
        }
        return dp[n];
    }
};