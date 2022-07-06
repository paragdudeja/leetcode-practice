class Solution {
public:
    // TC : O(M*N)
    // SC : O(N)
    int uniquePaths(int m, int n) {
        vector<int> curr(n), prev(n);
        prev[0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int top = prev[j];
                int left = j == 0 ? 0 : curr[j-1];
                curr[j] = top + left;
            }
            prev = curr;
        }
        return prev[n-1];
    }
    
    /*
    // TC: O(M*N)
    // SC : O(M*N)
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
    */
};