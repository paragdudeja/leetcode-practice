class Solution {
public:
    // TC : O(2^N)
    // SC : O(N * 2^N)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(0, nums, current, ans);
        return ans;
    }
    
    void solve(int idx, vector<int> &nums, vector<int> &current, vector<vector<int>> &ans) {
        if(idx == nums.size()) { // Base case
            ans.push_back(current);
            return;
        }
        
        // Pick
        current.push_back(nums[idx]);
        solve(idx + 1, nums, current, ans);
        current.pop_back();
        
        // Not Pick
        solve(idx + 1, nums, current, ans);
    }
};