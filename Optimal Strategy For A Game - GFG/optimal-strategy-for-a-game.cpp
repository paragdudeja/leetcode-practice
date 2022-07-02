// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int dp[1001][1001];
    int solve(int arr[], int n, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        if(i+1 == j) return dp[i][j] = max(arr[i], arr[j]);
        
        return dp[i][j] = max(arr[i] + min(solve(arr, n, i+2, j), solve(arr, n, i+1, j-1)),
                arr[j] + min(solve(arr, n, i, j-2), solve(arr, n, i+1, j-1)));
    }
    
    long long maximumAmount(int arr[], int n){
        memset(dp, -1, sizeof dp);
        return solve(arr, n, 0, n-1);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends