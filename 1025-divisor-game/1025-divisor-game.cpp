class Solution {
public:
    int dp[1001];
    bool solve(int n) {
        if(dp[n] != -1) return dp[n];
        if(n == 1) {
            return dp[n] = false;
        }
        else {
            for(int i = 1; i < n; i++) {
                if(n%i == 0 && solve(n-i)==false) {
                    return dp[n] = true;
                }
            }
        }
        return dp[n] = false;
    }
    
    bool divisorGame(int n) {
        memset(dp, -1, sizeof dp);
        return solve(n);
    }
};