class Solution {
public:
    // TC : O(M Log N)
    // SC : O(1)
    int countNegatives(vector<vector<int>>& grid) {
        int total_count = 0;
        for(int i = 0; i < grid.size(); i++) {
            int count_pos = getPosCount(grid[i]);
            total_count += grid[0].size() - count_pos;
        }
        return total_count;
    }
    
    int getPosCount(vector<int> &nums) {
        int low = 0, high = nums.size() - 1, count_pos = high + 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] < 0) {
                count_pos = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return count_pos;
    }
};