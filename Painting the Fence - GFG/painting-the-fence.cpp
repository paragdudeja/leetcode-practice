// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        if(n == 1) return k;
        const long long mod = 1e9 + 7;
        /*
        long long dp[n+1][2];
        dp[0][0] = dp[0][1] = 1;
        dp[1][0] = dp[1][1] = k;
        dp[2][0] = k;
        dp[2][1] = k * (k-1);
        for(int i = 3; i <= n; i++) {
            dp[i][0] = (dp[i-1][1])%mod;
            dp[i][1] = (((dp[i-1][0] + dp[i-1][1])%mod) * (k-1))%mod; 
        }
        return (dp[n][0] + dp[n][1])%mod;
        */
        long long same = k*1;
        long long diff = (k*(k-1))%mod;
        long long total = (same + diff)%mod;
        
        for(int i = 3; i <= n; i++) {
            same = diff;
            diff = (total * (k-1))%mod;
            total = (same + diff)%mod;
        }
        return total;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends