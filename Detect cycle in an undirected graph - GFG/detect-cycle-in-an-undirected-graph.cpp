// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool dfs(int s, int p, vector<int> adj[], bool visited[]){
        visited[s] = true;
        for(int &d: adj[s]){
            if(!visited[d]){
                if(dfs(d, s, adj, visited))
                    return true;
            }
            else if(d!=p)
                return true;
            
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        bool visited[V] = {};
        for(int i=0; i<V; i++)
            if(!visited[i])
                if(dfs(i, -1, adj, visited))
                    return true;
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends