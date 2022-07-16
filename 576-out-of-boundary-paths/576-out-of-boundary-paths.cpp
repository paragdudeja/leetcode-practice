class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
    
    int solve(int m, int n, int moves, int row, int col, vector<vector<vector<int>>> &dp) {
        if(moves < 0) return 0;
        if(row < 0 || row == m || col < 0 || col == n) return 1;
        
        if(dp[row][col][moves] != -1) return dp[row][col][moves];
        long long left = solve(m, n, moves-1, row, col-1, dp);
        long long right = solve(m, n, moves-1, row, col+1, dp);
        long long top = solve(m, n, moves-1, row-1, col, dp);
        long long bottom = solve(m, n, moves-1, row+1, col, dp);
        
        long long ans = (left + right + top + bottom)%(1000000007);
        return dp[row][col][moves] = ans;
    }
};