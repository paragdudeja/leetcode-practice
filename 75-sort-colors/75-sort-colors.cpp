class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = -1, mid = 0, high = nums.size();
        while(mid < high) {
            if(nums[mid] < 1) {
                swap(nums[++low], nums[mid++]);
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[--high]);
            }
        }
    }
};