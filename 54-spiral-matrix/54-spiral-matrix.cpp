class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        
        while(top <= bottom && left <= right) {
            // Top boundary
            for(int j = left; j <= right; ++j) {
                result.push_back(matrix[top][j]);
            }
            ++top;
            if(top > bottom) break;
            
            // Right boundary
            for(int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            --right;
            if(left > right) break;
            
            // Bottom boundary
            for(int j = right; j >= left; --j) {
                result.push_back(matrix[bottom][j]);
            }
            --bottom;
            
            // Left boundary
            if(top > bottom) break;
            for(int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            ++left;
        }
        
        return result;
    }
};