class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int low = 0;
        int high = nums.size() - 1;
        
        while(low < high) {
            int mid = low + (high - low)/2;
            if(nums[mid+1] > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};