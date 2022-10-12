class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // return (nums[0] + nums[1] > nums[2]) ? (nums[0] + nums[1] + nums[2]) : 0;
        int ans = 0;
        for(int i = 2; i < nums.size(); ++i) {
            if(nums[i-2] + nums[i-1] > nums[i]) {
                ans = nums[i-2] + nums[i-1] + nums[i];
            }
        }
        return ans;
    }
};