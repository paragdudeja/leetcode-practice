class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse rows
        for(vector<int> &row: matrix) {
            reverse(row.begin(), row.end());
        }
    }
};