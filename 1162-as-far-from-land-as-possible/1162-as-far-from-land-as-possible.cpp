class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j])
                    q.push({i, j});
            }
        }
        if(q.size() == 0 || q.size() == n*n) 
            return -1;
        
        int cnt = 0;
        int dirs[] = {0, 1, 0, -1, 0};
        
        // int cnt = 0;
        while(!q.empty()) {
            int count = q.size();
            while(count--) {
                auto point = q.front();
                q.pop();
                int x = point.first, y = point.second;
                for(int i = 0; i < 4; i++) {
                    int xx = x + dirs[i], yy = y + dirs[i+1];
                    if(xx<0||xx>=n||yy<0||yy>=n||grid[xx][yy]==1) continue;
                    grid[xx][yy] = 1;
                    q.push({xx, yy});
                }
            }
            cnt += q.size() > 0;
        }
        return cnt;
    }
};