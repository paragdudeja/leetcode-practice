class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = currentSum;
        
        for(int i = 1; i < nums.size(); ++i) {
            // either extend previous or start new
            currentSum = max(currentSum + nums[i], nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};