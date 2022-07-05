// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(arr, 1, N-1, dp);
    }
    
    int solve(int arr[], int l, int r, vector<vector<int>> &dp) {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX;
        
        for(int i = l; i < r; i++) {
            int temp = arr[l-1] * arr[i] * arr[r] + solve(arr, l, i, dp) + solve(arr, i+1, r, dp);
            ans = min(ans, temp);
        }
        return dp[l][r] = ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends