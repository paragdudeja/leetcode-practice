class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        for(const int &num: nums) {
            mp[num]++;
        }
        
        vector<pair<int, int>> v;
        for(auto &it: mp) {
            v.push_back({it.first, it.second});
        }
        
        vector<int> dp(nums.size()+1, -1);
        return solve(0, v, dp);
    }
    
    int solve(int index, vector<pair<int, int>> &v, vector<int> &dp) {
        if(index == v.size()) return 0;
        
        if(dp[index] != -1) return dp[index];      
        // Pick
        // ans = v[index].first * v[index].second;
        if(index + 1 < v.size() && v[index+1].first == v[index].first + 1) {
            return dp[index] = max(v[index].first * v[index].second + solve(index+2, v, dp), solve(index+1, v, dp));
        }
        return dp[index] = v[index].first * v[index].second + solve(index+1, v, dp);
        
    }
};