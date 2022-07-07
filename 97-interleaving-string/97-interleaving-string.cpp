class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int t = m + n;
        if(s3.size() != t) return false;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(s1, m, s2, n, s3, t, dp);
    }
    
    bool solve(string &s1, int m, string &s2, int n, string &s3, int t, vector<vector<int>> &dp) {
        if(t == 0) return true;
        if(dp[m][n] != -1) return dp[m][n];
        if(m > 0 && n > 0 && s1[m-1] == s3[t-1] && s2[n-1] == s3[t-1])
            return dp[m][n] = solve(s1, m-1, s2, n, s3, t-1, dp) || solve(s1, m, s2, n-1, s3, t-1, dp);
        
        if(m > 0 && s1[m-1] == s3[t-1])
            return dp[m][n] = solve(s1, m-1, s2, n, s3, t-1, dp);
        else if(n > 0 && s2[n-1] == s3[t-1])
            return dp[m][n] = solve(s1, m, s2, n-1, s3, t-1, dp);
        else 
            return dp[m][n] = false;
    } 
};