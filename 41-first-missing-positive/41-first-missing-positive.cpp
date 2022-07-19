class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i = 0;
        while(i < n) {
            if(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else {
                ++i;
            }
        }

        for(i = 1; i <= n; ++i) {
            if(nums[i-1] != i) break;
        }
        return i;
    }
    
    /*
    // TC : O(N)
    // SC : O(N)
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size(), i = 0;
        for(i = 1; i <= n; ++i) 
            if(s.find(i) == s.end()) break;
        return i;
    }
    */
};