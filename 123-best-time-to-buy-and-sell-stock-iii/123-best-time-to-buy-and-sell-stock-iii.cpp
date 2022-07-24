class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3));
        vector<vector<int>> curr(2, vector<int>(3));
        
        for(int i = n-1; i >= 0; --i) {
            for(int buy = 0; buy <= 1; ++buy) {
                for(int cap = 1; cap <= 2; ++cap) {
                    if(buy == 1) {
                        curr[buy][cap] = max(-prices[i] + after[0][cap], after[1][cap]);
                    }
                    else {
                        curr[buy][cap] = max(prices[i] + after[1][cap-1], after[0][cap]);
                    }
                }
            }
            after = curr;
        }
        return after[1][2];
    }
    
    /*
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3)));
        
        for(int i = n-1; i >= 0; --i) {
            for(int buy = 0; buy <= 1; ++buy) {
                for(int cap = 1; cap <= 2; ++cap) {
                    if(buy == 1) {
                        dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    }
                    else {
                        dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
    */
    
    /*
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
    */
};