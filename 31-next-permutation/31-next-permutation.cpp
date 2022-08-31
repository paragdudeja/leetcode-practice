class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1 = nums.size()-2, idx2 = -1;
        while(idx1 >= 0 && nums[idx1] >= nums[idx1 + 1]){
            idx1--;
        }
        if(idx1 != -1) {
            idx2 = nums.size()-1;
            while(idx2 > idx1 && nums[idx2] <= nums[idx1]) {
                idx2--;
            }
            swap(nums[idx1], nums[idx2]);
        }
        reverse(nums.begin() + idx1 + 1, nums.end());
    }
};