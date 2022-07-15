// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        int c[n+1][n+1];
        c[0][0]=0;
        if(n<r){
            return 0;
        }
        for(int i=1;i<=n;i++){
            c[i][0]=1;
            c[i][i]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%1000000007;
            }
        }
        return c[n][r]%1000000007;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends