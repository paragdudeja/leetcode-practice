class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for(const int &coin: coins) {
            for(int i = coin; i <= amount; i++) {
                // if(coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                // }
            }
        }
        
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};