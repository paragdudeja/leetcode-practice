class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> adj[n+1];
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int gap = 0; gap < n; gap++) {
            for(int i = 0, j = gap; j < n; i++, j++) {
                dp[i][j] = s[i] == s[j] && (gap < 2 || dp[i+1][j-1]);
                if(dp[i][j]) {
                    adj[i].push_back(j+1);
                }
            }
        }
        
        return bfs(adj, n);
    }
    
    int bfs(vector<int> adj[], int n) {
        vector<bool> vis(n+1);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int level = 0;
        
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                int node = q.front();
                q.pop();
                
                for(int dest: adj[node]) {
                    if(dest == n) return level;
                    if(!vis[dest]) {
                        q.push(dest);
                        vis[dest] = 1;
                    }
                }
            }
            level++;
        }
        return n;
    }
};