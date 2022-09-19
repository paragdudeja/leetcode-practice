class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> mp(1001);
        for(auto &v: nums) {
            for(auto &x: v) {
                mp[x]++;
            }
        }
        vector<int> ans;
        for(int i = 0; i < 1001; ++i) {
            if(mp[i] == n) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};