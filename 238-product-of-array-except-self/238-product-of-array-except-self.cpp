class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();    
        vector<int> left(n, 1);
        
        for(int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i-1];
        }
        
        int right = 1;
        for(int i = n-1; i >= 0; i--) {
            int temp = nums[i];
            nums[i] = left[i] * right;
            right = right * temp;
        }
        return nums;
    }
};