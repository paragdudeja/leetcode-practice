class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long dp[n + 1];
        const long long mod = 1e9 + 7;
        long long currentCount = 0;
        
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int add = dp[max(i - delay, 0)];
            int sub = dp[max(i - forget, 0)];
            currentCount = (currentCount + add - sub + mod)%mod;
            dp[i] = currentCount;
        }
        
        long long ans = 0;
        for(int i = n; i > n - forget; i--) {
            ans = (ans + dp[i])%mod;
        }
        return ans;
    }
};