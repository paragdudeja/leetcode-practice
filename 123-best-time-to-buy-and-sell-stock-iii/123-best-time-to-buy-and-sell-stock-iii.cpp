class Solution {
public:
    int dp[100001][3][2];
    int solve(int i, bool is_holding, vector<int> &prices, int k) {
        if(i == prices.size() || k == 0) {
            return 0;
        }
        if(dp[i][k][is_holding] != -1) return dp[i][k][is_holding];
        if(is_holding) {
            int sell = prices[i] + solve(i+1, false, prices, k-1);
            int notSell = solve(i+1, true, prices, k);
            return dp[i][k][is_holding] = max(sell, notSell);
        }
        else {
            int buy = -prices[i] + solve(i+1, true, prices, k);
            int notBuy = solve(i+1, false, prices, k);
            return dp[i][k][is_holding] = max(buy, notBuy);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return solve(0, false, prices, 2);
    }
};