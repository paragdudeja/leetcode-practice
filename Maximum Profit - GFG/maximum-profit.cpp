// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[501][201][2];
    int maxProfit(int K, int N, int A[]) {
        memset(dp, -1, sizeof dp);
        return solve(0, false, K, A, N);
    }
    
    int solve(int index, bool is_hold, int K, int A[], int N) {
        if(index == N || K == 0) return 0;
        
        if(dp[index][K][is_hold] != -1) return dp[index][K][is_hold];
        
        if(is_hold) {
            int sell = A[index] + solve(index+1, false, K-1, A, N);
            int notSell = solve(index+1, true, K, A, N);
            return dp[index][K][is_hold] = max(sell, notSell);
        }
        
        else {
            int buy = -A[index] + solve(index+1, true, K, A, N);
            int notBuy = solve(index+1, false, K, A, N);
            return dp[index][K][is_hold] = max(buy, notBuy);
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends