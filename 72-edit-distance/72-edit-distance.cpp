class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, s, t, dp);
    }
    
    int solve(int n, int m, string &s, string &t, vector<vector<int>> &dp) {
        if(n == 0 || m == 0)
            return max(m, n);
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1] == t[m-1])
            return dp[n][m] = solve(n-1, m-1, s, t, dp);
        
        int op1 = 1 + solve(n-1, m, s, t, dp);
        int op2 = 1 + solve(n, m-1, s, t, dp);
        int op3 = 1 + solve(n-1, m-1, s, t, dp);
        
        return dp[n][m] = min({op1, op2, op3});
    }
};