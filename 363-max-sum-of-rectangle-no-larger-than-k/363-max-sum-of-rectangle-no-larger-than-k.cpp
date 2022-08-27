class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = INT_MIN;
        
        for(int i = 0; i < row; ++i) {
            vector<int> current(col);
            for(int j = i; j < row; ++j) {
                for(int c= 0; c < col; ++c) {
                    current[c] += matrix[j][c];
                }
                ans = max(ans, findSum(current, k));
            }
        }
        
        return ans;
    }
    
    int findSum(vector<int> &nums, int k) {
        int result = INT_MIN;
        set<int> s;
        s.insert(0);
        
        int prefix = 0;
        for(int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];
            auto it = s.lower_bound(prefix - k);
            if(it != s.end()) {
                result = max(result, prefix - *it);
            }
            s.insert(prefix);
        }
        
        return result;
    }
};