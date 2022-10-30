class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if(k == 0 && grid[0][0] == 1) return -1;
        if(grid[0][0] == 1) --k;
        int steps = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        
        vector<vector<int>> available(m ,vector<int>(n, -1));
        
        queue<pair<int, pair<int, int>>> q;
        q.push({k, {0, 0}});
        available[0][0] = k;
        
        int dirs[] = {0, 1, 0, -1, 0};
        
        while(!q.empty()) {
            int cnt = q.size();
            for(int i = 0; i < cnt; ++i) {
                auto pt = q.front();
                q.pop();
                int kk = pt.first;
                int x = pt.second.first;
                int y = pt.second.second;
                
                if(x == m-1 && y == n-1) return steps;
                
                for(int t = 0; t < 4; ++t) {
                    int xx = x + dirs[t];
                    int yy = y + dirs[t + 1];
                    if(xx >= 0 && xx < m && yy >= 0 && yy < n) {
                        if(grid[xx][yy] == 0) {
                            if(available[xx][yy] < kk) {
                                available[xx][yy] = kk;
                                q.push({kk, {xx, yy}});
                            }
                        }
                        else if(grid[xx][yy] == 1 && kk > 0) {
                            if(available[xx][yy] < kk-1) {
                                available[xx][yy] = kk-1;
                                q.push({kk-1, {xx, yy}});
                            }
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};