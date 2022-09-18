class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == 0) return;
        reverse_vector(nums, 0, n-k);
        reverse_vector(nums, n-k, n);
        reverse_vector(nums, 0, n);
    }
    
    void reverse_vector(vector<int> &nums, int begin, int after_end) {
        for(int i = begin, j = after_end-1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
    }
};