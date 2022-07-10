class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        
        int n = cost.size();
        int prev1 = cost[0], prev2 = 0, current = 0;
        for(int i = 1; i < n; i++) {
            current = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
    
    /*
    // TC : O(N)
    // SC : O(N)
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        
        int n = cost.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = cost[0];
        
        for(int i = 1; i < n; i++) {
            dp[i+1] = min(dp[i], dp[i-1]) + cost[i];
        }
        return dp[n];
    }
    */
};