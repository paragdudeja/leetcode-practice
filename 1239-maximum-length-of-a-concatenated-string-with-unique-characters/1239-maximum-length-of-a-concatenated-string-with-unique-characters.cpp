class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int tablesize = (1<<n);
        vector<int> dp(tablesize);
        
        int ans = 0;
        for(int i = 1; i < tablesize; ++i) { // Interate over all combinations
            
            for(int j = 0; j < n; ++j) { // If current index part of current combination
                bool flag = false;
                if(i & (1<<j)) {
                    for(char ch: arr[j]) {
                        if(dp[i] & (1<<(ch - 'a'))) {
                            dp[i] = 0;
                            flag = true;
                            break;
                        }
                        dp[i] = dp[i] | (1<<(ch - 'a'));
                        
                    }
                    if(flag) break;
                }
            }
            
            ans = max(ans, __builtin_popcount(dp[i]));
        }
        
        
        return ans;
    }
};