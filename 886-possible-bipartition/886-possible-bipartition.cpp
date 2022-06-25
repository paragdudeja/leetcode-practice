class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        
        
        // Build adjacency matrix
        for(auto &edge: dislikes) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> colors(n+1);
        for(int i = 1; i <= n; i++) {
            if(colors[i] == 0) { // Node not colored yet
                if(dfsColoring(i, 1, colors, adj) == false) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool dfsColoring(int src, int color, vector<int> &colors, vector<vector<int>> &adj) {
        colors[src] = color;
        for(auto neighbor: adj[src]) {
            if(colors[neighbor] == 0) {
                if(dfsColoring(neighbor, -color, colors, adj) == false)
                    return false;
            }
            else if(colors[neighbor] == colors[src])
                return false;
        }
        return true;
    }
};