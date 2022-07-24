class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2);
        vector<int> curr(2);
        
        for(int i = n-1; i >= 0; --i) {
            curr[1] = max(-prices[i] - fee + ahead[0], ahead[1]);
            curr[0] = max(prices[i] + ahead[1], ahead[0]);
            ahead = curr;
        }
        return ahead[1];
    }
    
    /*
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2));
        
        for(int i = n-1; i >= 0; --i) {
            dp[i][1] = max(-prices[i] - fee + dp[i+1][0], dp[i+1][1]);
            dp[i][0] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
        }
        return dp[0][1];
    }
    */
    
    /*
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2));
        
        for(int i = n-1; i >= 0; --i) {
            for(int buy = 0; buy <= 1; ++buy) {
                if(buy) {
                    dp[i][buy] = max(-prices[i] - fee + dp[i+1][0], dp[i+1][1]);
                }
                else {
                    dp[i][buy] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
    */
    
    /*
    int dp[50000][2];
    int solve(int index, bool own, vector<int> &prices, int fee){
        if(index == prices.size()) return 0;
        
        if(dp[index][own] != -1) return dp[index][own];
        
        if(own){
            int op1 = prices[index] + solve(index+1, false, prices, fee); // sell
            int op2 = solve(index+1, true, prices, fee); // dont sell
            return dp[index][own] = max(op1, op2);
        }
        else{
            int op1 = -(prices[index] + fee) + solve(index+1, true, prices, fee); // buy
            int op2 = solve(index+1, false, prices, fee); // dont buy
            return dp[index][own] = max(op1, op2);
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof dp);
        return solve(0, false, prices, fee);
    }
    */
};