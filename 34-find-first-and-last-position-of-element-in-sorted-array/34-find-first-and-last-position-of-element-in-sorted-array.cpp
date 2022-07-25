class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        int last = upperBound(nums, target);

        return first == last ? vector<int>{-1, -1} : vector<int>{first, last-1};        
    }
    
    int lowerBound(vector<int> &nums, int x) {
        int idx = nums.size();
        int low = 0, high = idx - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] >= x) {
                idx = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return idx;
    }
    
    int upperBound(vector<int> &nums, int x) {
        int idx = nums.size();
        int low = 0, high = idx - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] > x) {
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