class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> mp;
        
        for(auto &n: nums) {
            if(n.size() < target.size()) mp[n]++;
        }
        
        
        int ans = 0;
        for(auto it: mp) {
            string s = it.first;
            int freq = it.second;
            
            if(s + s == target) {
                ans += freq * (freq-1);
            }
            
            else if(target.find(s) == 0) {
                ans += freq * mp[target.substr((int)s.size())];
            }
        }
        return ans;
    }
};