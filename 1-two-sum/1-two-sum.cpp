class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        for(int i = 0; i < nums.size(); i++) {
            if(idx.find(target - nums[i]) != idx.end()) {
                return {idx[target - nums[i]], i};
            }
            idx[nums[i]] = i;
        }
        return {};
    }
};