class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(isPossible(nums, m, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    bool isPossible(vector<int> nums, int k, int limit) {
        int sum = 0, count = 1;
        for(int &num: nums) {
            if(sum + num > limit) {
                sum = num;
                count++;
            }
            else {
                sum += num;
            }
            if(count > k) return false;
        }
        return true;
    }
};