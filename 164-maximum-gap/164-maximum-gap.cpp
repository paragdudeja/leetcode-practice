class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int mx_gap = 0;
        for(int i = 1; i < nums.size(); i++) {
            mx_gap = max(mx_gap, nums[i] - nums[i-1]);
        }
        return mx_gap;
     }
};