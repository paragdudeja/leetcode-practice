class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int left = 0, right = n-1;
        while(left <= right) {
            if(abs(nums[left]) > abs(nums[right])) {
                ans[--n] = nums[left] * nums[left++];
            }
            else {
                ans[--n] = nums[right] * nums[right--];
            }
        }
        return ans;
    }
};