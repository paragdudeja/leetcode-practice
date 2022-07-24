class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(k+1));
        vector<vector<int>> curr(2, vector<int>(k+1));
        
        for(int i = n-1; i >= 0; --i) {
            for(int buy = 0; buy <= 1; ++buy) {
                for(int cap = 1; cap <= k; ++cap) {
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
        return after[1][k];
    }
    /*
    int dp[1001][101][2];
    int solve(int index, bool own, int k, vector<int> &prices){
        if(dp[index][k][own] != -1) return dp[index][k][own];
        if(index == prices.size() || k==0) return dp[index][k][own] = 0;
        
        if(own){
            int op1 = prices[index] + solve(index+1, false, k-1, prices); // sell
            int op2 = solve(index+1, true, k, prices); // dont sell
            return dp[index][k][own] = max(op1, op2);
        }
        else{
            int op1 = -prices[index] + solve(index+1, true, k, prices); // buy
            int op2 = solve(index+1, false, k, prices); // dont buy;
            return dp[index][k][own] = max(op1, op2);
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return solve(0, false, k, prices);
    }
    */
};