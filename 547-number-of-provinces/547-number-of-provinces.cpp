class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<bool> vis(n);
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, n, vis, isConnected);
                count++;
            }
        }
        return count;
    }
    
    void dfs(int src, int n, vector<bool> &vis, vector<vector<int>> &graph) {
        vis[src] = true;
        for(int i = 0; i < n; i++) {
            if(graph[src][i] && !vis[i])
                dfs(i, n, vis, graph);
        }
    }
};