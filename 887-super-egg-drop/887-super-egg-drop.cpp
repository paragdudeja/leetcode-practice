class Solution {
public:
    // TC : O(K*N*LOgN)
    // SC : O(K * N)
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return solve(k, n, dp);
    }
    
    int solve(int e, int f, vector<vector<int>> &dp) {
        if(e == 1 || f <= 1) return f;
        if(dp[e][f] != -1) {
            return dp[e][f];
        }
        
        int ans = INT_MAX;
        int low = 1, high = f;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int left = solve(e-1, mid - 1, dp);
            int right = solve(e, f - mid, dp);
            int temp = 1 + max(left, right);
            if(left < right) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
            ans = min(ans, temp);
        }
        return dp[e][f] = ans;
    }
    
    /*
    // TC : O(K*N*N) i.e. O(K * N^2)
    // SC : O(K * N)
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return solve(k, n, dp);
    }
    
    int solve(int e, int f, vector<vector<int>> &dp) {
        if(e == 1 || f <= 1) return f;
        if(dp[e][f] != -1) {
            return dp[e][f];
        }
        
        int ans = INT_MAX;
        for(int i = 1; i <= f; i++) {
            int temp = 1 + max(solve(e-1, i-1, dp), solve(e, f - i, dp));
            ans = min(ans, temp);
        }
        return dp[e][f] = ans;
    }
    */
};