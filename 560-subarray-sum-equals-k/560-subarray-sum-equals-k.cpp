class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(const int &num: nums) {
            sum += num;
            ans += mp.find(sum - k) == mp.end() ? 0 : mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};