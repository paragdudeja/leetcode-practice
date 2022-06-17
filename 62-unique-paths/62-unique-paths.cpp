class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        grid[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int top = i == 0 ? 0 : grid[i - 1][j];
                int left = j == 0 ? 0 : grid[i][j - 1];
                grid[i][j] += top + left;
            }
        }
        return grid[m-1][n-1];
    }
};