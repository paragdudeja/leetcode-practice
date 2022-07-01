class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        
        for(const int &num: nums) {
            if(s.find(num-1) != s.end()) {
                continue;
            }
            int start = num;
            int end = num + 1;
            while(s.find(end) != s.end()) {
                end++;
            }
            longest = max(longest, end - start);
        }
        return longest;
    }
};