class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int &t: time) {
            t = t % 60;
            int comp = (60 - t)%60;
            ans += mp[comp];
            mp[t]++;
        }
        return ans;
    }
};