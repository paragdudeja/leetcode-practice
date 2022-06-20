class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Check if required shape is same as initial shape
        // or required shape is not compatible at all.
        // Return the input matrix as it is in both of these cases.
        if((m==r&& n==c) || (m*n != r*c)) return mat;
        
        vector<vector<int>> ans(r, vector<int>(c));
        int k = 0, l = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                ans[i][j] = mat[k][l];
                l++;
                if(l == n) {
                    k++;
                    l = 0;
                }
            }
        }
        return ans;
    }
};