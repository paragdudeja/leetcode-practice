// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int dp[100001][3][2];
int solve(int index, bool is_hold, int K, vector<int> &A, int N) {
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

int maxProfit(vector<int>&price){
    //Write your code here..
    memset(dp, -1, sizeof dp);
    return solve(0, false, 2, price, price.size());
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends