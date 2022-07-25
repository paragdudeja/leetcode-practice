class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int hash[n];
        
        sort(nums.begin(), nums.end());
        int longest = 0;
        int lastIndex = 0;
        int dp[n];
        for(int i = 0; i < n; ++i) {
            hash[i] = i;
            dp[i] = 1;
  
            for(int j = 0; j < i; ++j) {
                if((nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            
            if(dp[i] > longest) {
                longest = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> ans;
        while(ans.size() < longest) {
            ans.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};