class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int, int> mp;   
        for(auto &v: nums) {
            for(auto &x: v) {
                mp[x]++;
            }
        }
        vector<int> ans;
        for(auto it: mp) {
            if(it.second == n) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};