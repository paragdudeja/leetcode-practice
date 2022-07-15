class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int largest = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                largest = max(largest, dfs(i, j, grid));
            }
        }
        return largest;
    }
    
    int dfs(int i, int j, vector<vector<int>> &grid) {
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        return 1 + dfs(i+1, j, grid) + dfs(i-1, j, grid) + dfs(i, j+1, grid) + dfs(i, j-1, grid);
    }
};