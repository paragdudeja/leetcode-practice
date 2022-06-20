class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, current, result);
        return result;
    }
    
    void solve(int idx, int target, vector<int>& candidates, vector<int> &current, vector<vector<int>> &result) {
        if(idx == candidates.size()) {
            if(target == 0) {
                result.push_back(current);
            }
            return;
        }
        
        if(candidates[idx] <= target) {
            current.push_back(candidates[idx]);
            solve(idx, target - candidates[idx], candidates, current, result);
            current.pop_back();
        }
        
        solve(idx+1, target, candidates, current, result);
    }
};