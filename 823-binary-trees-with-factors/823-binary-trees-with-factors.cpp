class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<long long> dp(n, 1);
        unordered_map<int, int> m;
        
        m[nums[0]] = 0;
        
        const long long MOD = 1000000007;
        for(int i = 1; i < n; ++i) {
            m[nums[i]] = i;
            for(int j = 0; j < i; ++j) {
                if(nums[i] % nums[j] == 0) {
                    int complement = nums[i] / nums[j];
                    if(m.count(complement)) {
                        dp[i] += (dp[j] * dp[m[complement]])%MOD;
                    }
                }
            }
        }
        
        long long ans = 0;
        for(auto i: dp) {
            ans = (ans + i)%MOD;
        }
        
        return ans;
    }
};