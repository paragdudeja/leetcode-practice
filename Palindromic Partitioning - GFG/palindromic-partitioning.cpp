// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        // Make graph
        vector<int>  adj[n+1];
        
        for(int gap = 0; gap < n; gap++) {
            for(int i = 0, j = gap; j < n; i++, j++) {
                if(gap == 0) {
                    dp[i][j] = 1;
                }
                else if(gap == 1) {
                    dp[i][j] = str[i] == str[j];
                }
                else {
                    dp[i][j] = str[i] == str[j] && dp[i+1][j-1] == 1;
                }
                
                if(dp[i][j]) {
                    adj[i].push_back(j+1);
                }
            }
        }
        
        // BFS
        vector<bool> visited(n+1);
        int cuts = 0;
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        
        /*
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        */
        
        
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                int node = q.front();
                q.pop();
                
                for(int &dest: adj[node]) {
                    if(dest == n) return cuts;
                    if(!visited[dest]) {
                        visited[dest] = 1;
                        q.push(dest);
                    }
                }
            }
            cuts++;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends