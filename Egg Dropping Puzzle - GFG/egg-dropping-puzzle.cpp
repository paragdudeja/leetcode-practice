// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int eggDrop(int n, int k) 
    {
        memset(dp, -1, sizeof dp);
        return solve(n, k);
    }
    
    int solve(int e, int f) {
        if(e == 1 || f == 1 || f == 0) return f;
        if(dp[e][f] != -1) return dp[e][f];
        
        int ans = INT_MAX;
        
        for(int i = 1; i <= f; i++) {
            int temp = max(solve(e-1, i-1), solve(e, f - i));
            ans = min(ans, 1 + temp);
        }
        return dp[e][f] = ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends