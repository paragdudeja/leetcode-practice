class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();
        if(forest[0][0] == 0) return -1;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(forest[i][j] > 1)
                    pq.push({forest[i][j], {i, j}});
            }
        }
        
        int start_row = 0, start_col = 0;
        int total_steps = 0; 
        while(!pq.empty()) {
            auto data = pq.top();
            pq.pop();
            int steps = min_distance(start_row, start_col, data.second.first, data.second.second, forest, m, n);
            if(steps == -1) return -1;
            total_steps += steps;
            start_row = data.second.first;
            start_col = data.second.second;
        }
        
        return total_steps;
    }
    
    int min_distance(int i, int j, int ti, int tj, vector<vector<int>> graph, int m, int n) {
        queue<pair<int, int>> q;
        int steps = 0;
        q.push({i, j});
        graph[i][j] = 0;
        int dirs[] = {0, 1, 0, -1, 0};
        
        while(!q.empty()) {
            int count = q.size();
            
            for(int i = 0; i < count; i++) {
                auto pos = q.front();
                q.pop();
                if(pos.first == ti && pos.second == tj) return steps;
                
                for(int j = 0; j < 4; j++) {
                    int ni = pos.first + dirs[j], nj = pos.second + dirs[j+1];
                    if(ni >= 0 &&  ni < m && nj >= 0 && nj < n && graph[ni][nj] != 0) {
                        graph[ni][nj] = 0;
                        q.push({ni, nj});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};