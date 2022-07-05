// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        
        // vector<int> dp(N, 1);
        int dp[N];
        dp[0] = 1;
        int mx = 1;
        
        for(int i = 1; i < N; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(A[j]-A[i] == 1 || A[j]-A[i] == -1) {
                    dp[i] = max(dp[i], 1+ dp[j]);
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
        
        /*
        int dp[10001] = {0}, ans = 0;
        for(int i=0; i<N; i++){
            dp[A[i]] = max(1+dp[A[i]-1], 1+dp[A[i]+1]);
            ans = max(ans, dp[A[i]]);
        }
        return ans;
        */
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends