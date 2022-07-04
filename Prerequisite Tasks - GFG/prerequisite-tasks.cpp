// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    
	    for(const auto &p: prerequisites) {
	        int u = p.second, v = p.first;
	        adj[u].push_back(v);
	    }
	    
	    vector<bool> vis(N), dfsvis(N);
	    for(int i = 0; i < N; i++) {
	        if(!vis[i] && isCyclePresent(i, vis, dfsvis, adj))
	            return false;
	    }
	    return true;
	}
	
	bool isCyclePresent(int src, vector<bool> &vis, vector<bool> &dfsvis, vector<int> adj[]) {
	    vis[src] = true;
	    dfsvis[src] = true;
	    
	    for(int &dest: adj[src]) {
	        if(!vis[dest] && isCyclePresent(dest, vis, dfsvis, adj)) {
	            return true;
	        }
	        else if(dfsvis[dest]) {
	            return true;
	        }
	    }
	    dfsvis[src] = false;
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends