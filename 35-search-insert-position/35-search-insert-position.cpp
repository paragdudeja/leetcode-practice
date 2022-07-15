class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() -1, idx = nums.size();
        if(target < nums[0]) return 0;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] >= target) {
                idx = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return idx;
    }
};