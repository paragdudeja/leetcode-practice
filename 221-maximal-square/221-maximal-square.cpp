class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // if(matrix.empty()) return 0;
        int m = matrix.size();
        // if(m == 0) return 0;
        int n = matrix[0].size();
        // if(n == 0) return 0;
        
        int dp[m][n];
        int mxSide = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0 || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                if(dp[i][j] > mxSide) mxSide = dp[i][j];
            }
        }
        return mxSide * mxSide;        
    }
};