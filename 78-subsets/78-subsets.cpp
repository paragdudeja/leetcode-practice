class Solution {
public:
    // TC : O(2^N * N)
    // SC : O(N)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        solve(0, nums, current, result);
        return result;
    }
    
    void solve(int index, vector<int> &nums, vector<int> &current, vector<vector<int>> &result) {
        if(index == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Pick
        current.push_back(nums[index]); // Add to end the number at current index
        solve(index + 1, nums, current, result); // Genrate combinations after picking current
        current.pop_back(); // Remove last item after coming back
        
        // Not Pick
        solve(index + 1, nums, current, result); // / Genrate combinations without picking current
    }
};