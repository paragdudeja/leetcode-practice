class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int op1 = j == 0 ? 1e9 : matrix[i-1][j-1];
                int op2 = matrix[i-1][j];
                int op3 = j == n-1 ? 1e9 : matrix[i-1][j+1];
                matrix[i][j] += min({op1, op2, op3});
            }
        }
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};