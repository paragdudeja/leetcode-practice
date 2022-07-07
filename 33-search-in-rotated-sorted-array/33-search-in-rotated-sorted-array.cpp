class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums);
        // cout << pivot << endl;
        
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int rotated = (mid + pivot) % n;
            if(nums[rotated] == target) {
                return rotated;
            }
            else if(nums[rotated] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
    
    int getPivot(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        
        if(nums[low] < nums[high]) return low;
        
        while(low < high) {
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }   
    
};