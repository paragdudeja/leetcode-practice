class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        helper(1, k, n, current, result);
        return result;
    }
    
    void helper(int start, int k, int target, vector<int> &curr, vector<vector<int>> &res) {
        if(curr.size() == k) {
            if(target == 0) {
                res.push_back(curr);
            }
            return;
        }
        
        for(int i = start; i < 10; i++) {
            if(i > target) break;
            curr.push_back(i);
            helper(i + 1, k, target - i, curr, res);
            curr.pop_back();
        }
    }
};