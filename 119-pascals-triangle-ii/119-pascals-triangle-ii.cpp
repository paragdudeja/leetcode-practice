class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        
        for(int i = 1; i <= rowIndex; i++) {
            ans[i] = (int)((long long)ans[i-1] * (rowIndex - i + 1) / i);
        }
        return ans;
    }
};