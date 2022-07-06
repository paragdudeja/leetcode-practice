class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int dp[n][n];
        for(int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }        
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int min_val = INT_MAX;
                for(int k = 0; k < n; k++) {
                    if(k != j && dp[i-1][k] < min_val) {
                        min_val = dp[i-1][k];
                    }
                }
                dp[i][j] = grid[i][j] + min_val;
            }
        }
        
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};