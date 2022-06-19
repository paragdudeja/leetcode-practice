class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        int ans = 0;
        int id = 2;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    mp[id] = dfs(id, i, j, grid, m, n);
                    id++;
                }
            }
        }
        
        // if(mp[2] == m*n) return m*n;
        vector<int> dirs{0,1,0,-1,0};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> sid;
                    int current = 1;
                    for(int k = 0; k < 4; k++) {
                        int ni = i + dirs[k], nj = j + dirs[k+1];
                        if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] > 1) {
                            if(sid.find(grid[ni][nj]) == sid.end()) {
                                current += mp[grid[ni][nj]];
                                sid.insert(grid[ni][nj]);
                            }
                        }
                    }
                    ans = max(ans, current);
                }
            }
        }
        
        return ans == 0 ? mp[2] : ans;
    }
    
    int dfs(int id, int i, int j, vector<vector<int>>& grid, int m, int n) {
        if(i < 0 || j < 0 || i == m || j == n || grid[i][j] == 0 || grid[i][j] > 1) return 0;
        grid[i][j] = id;
        return 1 + dfs(id, i+1, j, grid, m, n) + dfs(id, i, j+1, grid, m, n)
            + dfs(id, i-1, j, grid, m, n) + dfs(id, i, j-1, grid, m, n);
    }
};