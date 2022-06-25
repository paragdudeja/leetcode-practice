class Solution {
public:
    void dfs(int i, vector<bool> &vis, vector<vector<int>> &adj, int &size) {
        vis[i] = true;
        size++;
        for(auto it: adj[i]) {
            if(!vis[it])
                dfs(it, vis, adj, size);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        
        vector<vector<int>> adj(n);
        
        for(auto &edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> compo;
        vector<bool> vis(n);
        int size = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]){
                dfs(i, vis, adj, size);
                compo.push_back(size);
                size = 0;
            }
        }
        
        if(compo.size() < 2) return 0;
        
        long long array_sum = 0;
        for (int &s: compo)
            array_sum = array_sum + s;

        
        long long array_sum_square = array_sum * array_sum;

        // calculating a1^2 + a2^2 + ... + an^2
        long long individual_square_sum = 0;
        for (int &s: compo)
            individual_square_sum += (long long)s*s;

        // required sum is (array_sum_square -
        // individual_square_sum) / 2
        return (array_sum_square - individual_square_sum)/2;
    }
};