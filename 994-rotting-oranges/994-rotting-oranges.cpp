class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int fresh = 0;
        queue<pair<int, int>> q; // for rotten
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        if(fresh == 0) return 0;
        int dir[] = {0, 1, 0, -1, 0};
        
        int steps = 0;
        while(!q.empty()) {
            int count = q.size();
            for(int k = 0; k < count; k++) {
                auto pos = q.front();
                q.pop();
                
                int x = pos.first, y = pos.second;
                for(int i = 0; i < 4; i++) {
                    int nx  = x + dir[i], ny = y + dir[i+1];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            steps += !q.empty();
        }
        
        return fresh > 0 ? -1 : steps;
    }
};