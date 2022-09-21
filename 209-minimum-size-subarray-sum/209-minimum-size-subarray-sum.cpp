class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, sum = 0;
        int min_len = 1e6;
        bool flag = false;
        
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while(sum >= target) {
                flag = true;
                // if(min_len > i - start + 1) min_len = i - start + 1;
                sum -= nums[start];
                start++;
            }
            if(flag) {
                flag = false;
                if(min_len > i - start +  + 2) min_len = i - start + 2;
            }
        }
        
        return min_len == 1e6 ? 0 : min_len;
    }
};