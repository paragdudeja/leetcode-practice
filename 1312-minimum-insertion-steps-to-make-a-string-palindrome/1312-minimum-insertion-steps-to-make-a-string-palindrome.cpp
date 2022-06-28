class Solution {
public:
    // TC : O(N^2)
    // SC : O(N)
    int minInsertions(string s) {
        int n = s.size();
        vector<int> prev(n+1), curr(n+1);
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == s[n - j]) {
                    curr[j] = 1 + prev[j - 1];
                }
                else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        int lps = prev[n];
        return n - lps;
    }
    
    /*
    // TC : O(N^2)
    // SC : O(N^2)
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == s[n - j]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int lps = dp[n][n];
        int res = n - lps;
        return res;
    }
    */
};