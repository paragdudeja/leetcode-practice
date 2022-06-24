class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        
        for(int i = 0; i < n; i++) {
            if(color[i] == 0) { // Not colores, not visited yet
                if(colorNodes(i, 1, color, graph) == false) 
                    return false;
            }
        }
        return true;
    }
    
    bool colorNodes(int src, int col, vector<int> &color, vector<vector<int>> &graph) {
        color[src] = col;
        
        for(const auto &dest: graph[src]) {
            if(color[dest] == 0) {
                if(colorNodes(dest, -col, color, graph) == false) {
                    return false;
                }
            }
            else if(color[dest] == color[src]) {
                return false;
            }
        }
        
        return true;
    }
};