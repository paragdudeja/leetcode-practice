class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        
        int n = graph.size();
        dfs(0, n-1, graph, path, result);
        return result;
    }
    
    void dfs(int source, int target, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &result) {
        path.push_back(source);
        if(source == target){
            result.push_back(path);
            path.pop_back();
            return;
        }
        
        for(const int &neighbor: graph[source]) {
            dfs(neighbor, target, graph, path, result);
        }
        path.pop_back();
    }

};