class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,  vector<int>(n));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int left = j == 0 ? 0 : dp[i][j-1];
                int top = i == 0 ? 0 : dp[i-1][j];
                dp[i][j] += left + top;
            }
        }
        return dp[m-1][n-1];
    }
};