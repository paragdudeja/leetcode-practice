class Solution {
public:
    int minDifficulty(vector<int>& job, int d) {
        int n = job.size();
        if(n < d) return -1;
        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));
        return solve(0, d, job, n, dp);
    }
    
    int solve(int idx, int d, vector<int> &job, int n, vector<vector<int>> &dp) {  
        if(dp[idx][d] != -1) return dp[idx][d];
        
        if(d == 1) {
            int mx = 0;
            for(int i = idx; i < n; ++i) {
                mx = max(mx, job[i]);
            }
            return mx;
        }
        
        int mx = 0;
        int ans = INT_MAX;
        
        for(int i = idx; i < n-d+1; ++i) {
            mx = max(mx, job[i]);
            ans = min(ans, mx + solve(i+1, d-1, job, n, dp));
        }
        return dp[idx][d] = ans;
    }
    
};