class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, sum = 0;
        int min_len = 1e6;
        
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while(sum >= target) {
                min_len = min(min_len, i - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        
        return min_len == 1e6 ? 0 : min_len;
    }
};