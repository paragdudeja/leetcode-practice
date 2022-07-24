class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int mx = 1;
        int n = nums.size();
        pair<int, int> dp[n];
        
        for(int i = 0; i < n; ++i) {
            dp[i] = {1, 1};
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    int len = 1 + dp[j].first;
                    if(len > dp[i].first) {
                        dp[i] = {len, dp[j].second};
                    }
                    else if(len == dp[i].first) {
                        dp[i].second += dp[j].second;
                    }
                }
            }
            mx = max(mx, dp[i].first);
        }
        // cout << mx << endl;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(dp[i].first == mx) {
                ans += dp[i].second;
            }
        }
        return ans;
    }
};