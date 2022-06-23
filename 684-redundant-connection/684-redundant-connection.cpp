class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            // rank[i] = 0;
        }
    }
    
    int getParent(int v) {
        return v == parent[v] ? v : parent[v] = getParent(parent[v]);
    }
    
    void unite(int u, int v) {
        u = getParent(u);
        v = getParent(v);
        
        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[u] > rank[v]) {
            parent[v] = u;
        }
        else {
            rank[u]++;
            parent[v] = u;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);    
        
        vector<int> removed_edge;
        
        for(const auto &edge: edges) {
            int u = edge[0], v = edge[1];
            if(dsu.getParent(u) != dsu.getParent(v))
                dsu.unite(u, v);
            else
                removed_edge = edge;
        }
        return removed_edge;
    }
};