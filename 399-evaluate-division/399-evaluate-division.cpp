class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>> > adj;
        
        int n = values.size();
        for(int i = 0; i < n; i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        
        int q = queries.size();
        vector<double> ans(q);
        
        unordered_set<string> visited;
        double sol = -1.0;
        for(int i = 0; i < q; i++) {
            sol = -1.0;
            if(adj.count(queries[i][0]) == 0 || adj.count(queries[i][1]) == 0) {
                ans[i] = sol;
                continue;
            }
            dfs(queries[i][0], queries[i][1], sol, 1.0, adj, visited);
            ans[i] = sol;
        }
        
        return ans;
    }
    
    void dfs(string &start, string &end, double &sol, double current, unordered_map<string, vector<pair<string, double>>> &adj
            , unordered_set<string> &visited) {
        if(start == end) {
            sol = current;
            return;
        }
        visited.insert(start);
        for(auto &it: adj[start]) {
            if(visited.count(it.first) == 0) {
                dfs(it.first, end, sol, current * it.second, adj, visited);
            }
        }
        visited.erase(visited.find(start));
    }
};