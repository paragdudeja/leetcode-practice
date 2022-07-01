// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int prefixStrings(int N)
	{
	    long long dp[N+1];
	    const long long  MOD = 1e9 + 7;
	    dp[0] = 1;
	    for(int i = 1; i <= N; i++) {
	        dp[i] = 0;
	        for(int j = 0; j < i; j++) {
	            dp[i] = (dp[i] + (dp[j] * dp[i - j - 1])%MOD)%MOD;
	        }
	    }
	    return dp[N];
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n;
       	cin >> n;

       

        Solution ob;
        cout << ob.prefixStrings(n);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends