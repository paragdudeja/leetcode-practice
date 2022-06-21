class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> result;
        helper(1, n, k, current, result);
        return result;
    }
    
    void helper(int start, int n, int k, vector<int> &curr, vector<vector<int>> &res) {
        if(k == 0) {
            res.push_back(curr);
            return;
        }
        
        for(int i = start; i <= n; i++) {
            curr.push_back(i);
            helper(i + 1, n, k - 1, curr, res);
            curr.pop_back();
        }
    }
    
    
};