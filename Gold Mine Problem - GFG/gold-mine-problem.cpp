// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        for(int j = 1; j < m; j++) {
            for(int i = 0; i < n; i++) {
                int op1 = i == 0 ? : M[i-1][j-1];
                int op2 = M[i][j-1];
                int op3 = i == n-1 ? 0 : M[i+1][j-1];
                M[i][j] += max({op1, op2, op3});
            }
        }
        int mx = 0;
        for(int i = 0; i < n; i++)
            mx = max(mx, M[i][m-1]);
        return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends