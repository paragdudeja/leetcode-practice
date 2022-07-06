class Solution {
public:
    // TC : O(M*N)
    // SC : O(1)
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(i > 0 && j > 0 && matrix[i][j]) {
                    matrix[i][j] = 1 + min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]});
                }
                count += matrix[i][j];
            }
        }
        return count;
    }
};