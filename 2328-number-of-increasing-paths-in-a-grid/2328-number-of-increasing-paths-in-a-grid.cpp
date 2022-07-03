class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n));
        long long ans = 0;
        const long long mod = 1e9 + 7;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = ((ans + dfs(i, j, m, n, grid, dp, 0)))%mod;
            }
        }
        return ans;
    }
    
    long long dfs(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<long long>> &dp, int prev) {
        if(i < 0 || i == m || j < 0 || j == n || grid[i][j] <= prev) return 0;
        
        if(dp[i][j] > 0) return dp[i][j];
        const long long mod = 1e9 + 7;
        
        long long top = dfs(i-1, j, m, n, grid, dp, grid[i][j]);
        long long bottom = dfs(i+1, j, m, n, grid, dp, grid[i][j]);
        long long left = dfs(i, j-1, m, n, grid, dp, grid[i][j]);
        long long right = dfs(i, j+1, m, n, grid, dp, grid[i][j]);
        
        return dp[i][j] = ((1 + (((left + right)%mod + top)%mod + bottom)%mod))%mod;
    }
};