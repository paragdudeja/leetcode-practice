class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                else {
                    grid[i][j] = 1e9;
                }
            }
        }
        
        if(q.size() == 0 || q.size() == n*n)
            return -1;
        
        vector<int> dirs{0, 1, 0, -1, 0};
        int mxDist = 0;
        while(!q.empty()) {
            int count = q.size();
            
            for(int i = 0; i < count; i++) {
                auto pos = q.front();
                q.pop();
                int x = pos.first, y = pos.second;
                for(int j = 0; j < 4; j++) {
                    int newx = x + dirs[j], newy = y + dirs[j+1];
                    if(newx >= 0 && newy >= 0 && newx < n && newy < n && grid[newx][newy] > 1 + grid[x][y]) {
                        q.push({newx, newy});
                        grid[newx][newy] = 1 + grid[x][y];
                        mxDist = max(mxDist, grid[newx][newy]);
                    }
                }
            }
        }
        return mxDist;
    }
};