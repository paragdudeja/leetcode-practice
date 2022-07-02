class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    
    int getParent(int v) {
        return v == parent[v] ? v : parent[v] = getParent(parent[v]);
    }
    
    void unite(int u, int v) {
        u = getParent(u);
        v = getParent(v);
        if(rank[u] > rank[v]) {
            parent[v] = u;
        }
        else if(rank[v] > rank[u]) {
            parent[u] = v;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        
        for(const string &eq: equations) {
            int u = eq[0] - 'a';
            int v = eq[3] - 'a';
            if(eq[1] == '=') {   
                dsu.unite(u, v);
            }
        }
        
        for(const string &eq: equations) {
            int u = eq[0] - 'a';
            int v = eq[3] - 'a';
            if(eq[1] == '!'){   
                if(dsu.getParent(u) == dsu.getParent(v)) {
                    return false;
                }
            }
        }
        return true;
    }
};