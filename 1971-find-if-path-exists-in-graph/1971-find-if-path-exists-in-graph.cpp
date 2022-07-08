class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n);
        vector<int> adj[n];
        for(const vector<int> &edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return dfs(source, destination, vis, adj);
    }
    
    bool dfs(int src, int dest, vector<bool> &vis, vector<int> adj[]) {
        vis[src] = 1;
        if(src == dest) return true;
        for(int &v: adj[src]) {
            if(!vis[v] && dfs(v, dest, vis, adj)) {
                return true;
            }
        }
        return false;
    }
};