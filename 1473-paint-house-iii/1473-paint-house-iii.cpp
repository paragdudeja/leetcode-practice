class Solution {
public:
    int dp[101][101][21];
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof dp);
        int min_cost = solve(0, target, 0, m, n, houses, cost);
        return min_cost == 1e9 ? -1: min_cost;
    }
    
    int solve(int index, int target, int prev, int m, int n, vector<int> &houses, vector<vector<int>> &cost) {
        if(target < 0) {
            return 1e9;
        }
        
        if(index == m) {
            return target == 0 ? 0 : 1e9;
        }
        
        if(dp[index][target][prev] != -1) return dp[index][target][prev];
        
        if(houses[index] != 0) { // already painted
            return solve(index+1, target - (prev != houses[index]), houses[index], m, n, houses, cost);
        }
        
        int ans = 1e9;
        for(int i = 1; i <= n; i++) {
            ans = min(ans, cost[index][i-1] + solve(index+1, target - (prev != i), i, m, n, houses, cost));
        }
        
        return dp[index][target][prev] = ans;        
    }
};