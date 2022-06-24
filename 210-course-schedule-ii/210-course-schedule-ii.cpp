class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(auto &edge: prerequisites) {
            int u = edge[1], v = edge[0];
            adj[u].push_back(v);
        }
        
        vector<bool> vis(numCourses), dfsvis(numCourses);
        stack<int> st;
        
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(cycleCheck(i, vis, dfsvis, st, adj)) {
                    return {};
                }
            }
        }
        
        vector<int> topoSort;
        while(!st.empty()) {
            topoSort.push_back(st.top());
            st.pop();
        }
        
        return topoSort;
    }
    
    bool cycleCheck(int src, vector<bool> &vis, vector<bool> &dfsvis, stack<int> &st, vector<vector<int>> &adj) {
        vis[src] = true;
        dfsvis[src] = true;
        
        for(auto &dest: adj[src]) {
            if(!vis[dest]){
                if(cycleCheck(dest, vis, dfsvis, st, adj))
                    return true;
            }
            else if(dfsvis[dest])
                return true;
        }
        
        st.push(src);
        dfsvis[src] = false;
        return false;
    }
};