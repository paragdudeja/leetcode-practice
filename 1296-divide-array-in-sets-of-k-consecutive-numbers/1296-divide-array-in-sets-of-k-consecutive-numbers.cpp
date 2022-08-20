class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // multiset<int> s(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for(int x: nums) {
            m[x]++;
        }
        
        for(int x: nums) {
            if(m[x] == 0) continue;
            m[x]--;
            for(int i = 1; i < k; ++i) {
                if(m[x+i] == 0) return false;
                m[x+i]--;
            }
        }
        return true;
    }
};