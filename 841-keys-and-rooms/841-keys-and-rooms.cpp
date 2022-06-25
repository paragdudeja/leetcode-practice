class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n);
        
        // Perform dfs to find all nodes reachable from 0
        dfs(0, visited, rooms);
        
        
        // Check if any node is left unvisited
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                return false;
        }
        return true;
    }
    
    void dfs(int source, vector<bool> &visited, vector<vector<int>> &graph) {
        visited[source] = true;
        for(auto neighbor: graph[source])
            if(!visited[neighbor])
                dfs(neighbor, visited, graph);
    }
};