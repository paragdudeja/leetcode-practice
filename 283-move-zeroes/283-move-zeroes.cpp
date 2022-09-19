class Solution {
public:
    /*
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, countNonZero = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                swap(nums[i], nums[countNonZero++]);
            }
        }
    }
    */
    
    void moveZeroes(vector<int>& nums) {
        int count = 0;  // Count of non-zero elements
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] != 0)
                nums[count++] = nums[i]; // here count is
                                       // incremented
        while (count < n)
            nums[count++] = 0;
    }
};