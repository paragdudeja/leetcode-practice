// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        
        long long prev1 = 1, prev2 = 1;
        const long long MOD = 1e9 + 7;
        
        for(int i = 2; i <= n; i++) {
            long long curr = (prev1 + ((i-1)*prev2)%MOD)%MOD;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        
        /*
        long long dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = (dp[i-1] + ((i-1)*dp[i-2])%MOD)%MOD;
        }
        return dp[n];
        */
        
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends