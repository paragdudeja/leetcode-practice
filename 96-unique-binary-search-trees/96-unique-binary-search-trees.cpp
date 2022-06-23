class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0, k = i - 1; j < i; j++, k--) {
                dp[i] += dp[j] * dp[k];
            }
        }
        return dp[n];
    }
    
    /*
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return getCount(n, dp);
    }
    
    int getCount(int n, vector<int> &dp) {
        if(n == 0)
            return 1;
        
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int left = getCount(i-1, dp); 
            int right = getCount(n-i, dp);
            ans += left * right;
        }
        
        return dp[n] = ans;
    }
    */
};