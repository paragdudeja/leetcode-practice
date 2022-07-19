class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size(), i = 0;
        for(i = 1; i <= n; ++i) 
            if(s.find(i) == s.end()) break;
        return i;
    }
};