class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(grid, n, m, 0, 0, m-1, dp);
    }
    
    int solve(vector<vector<int>> &grid, int n, int m, int row, int col1, int col2, vector<vector<vector<int>>> &dp) {
        if(row == n || col1 < 0 || col1 == m || col2 < 0 || col2 == m) {
            return 0;
        }
        
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
        
        int maxCherries = 0;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                int newCol1 = col1 + i;
                int newCol2 = col2 + j;
                int newRow = row + 1;
                maxCherries = max(maxCherries, solve(grid, n, m, newRow, newCol1, newCol2, dp));
            }
        }
        
        int currentCherries = 0;
        if(col1 == col2) {
            currentCherries = grid[row][col1];
        }
        else {
            currentCherries = grid[row][col1] + grid[row][col2];
        }
        
        return dp[row][col1][col2] = currentCherries + maxCherries;
    }
};