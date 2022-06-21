class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        vector<vector<int>> result;
        helper(0, candidates, target, current, result);
        return result;
    }
    
    void helper(int index, vector<int> &nums, int target, vector<int> &curr, vector<vector<int>> &res) {
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        
        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i-1]) continue;
            
            if(nums[i] > target) break;
            curr.push_back(nums[i]);
            helper(i + 1, nums, target - nums[i], curr, res);
            curr.pop_back();
        }
    }
};