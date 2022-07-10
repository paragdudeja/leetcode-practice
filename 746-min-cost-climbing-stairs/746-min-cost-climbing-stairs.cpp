class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        
        int n = cost.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = cost[0];
        dp[2] = cost[1];
        
        for(int i = 2; i < n; i++) {
            dp[i+1] = min(dp[i], dp[i-1]) + cost[i];
        }
        return dp[n];
    }
};