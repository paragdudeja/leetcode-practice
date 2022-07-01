class Solution {
public:
    // Binary search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m*n - 1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(matrix[mid/n][mid%n] == target) {
                return true;
            }
            else if(matrix[mid/n][mid%n] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
    
    /*
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = m - 1, col = 0;
        while(row >= 0 && col < n) {
            if(matrix[row][col] == target) {
                return true;
            }
            else if(matrix[row][col] < target) {
                col++;
            }
            else {
                row--;
            }
        }
        return false;
    }
    */
    
    /*
    // Start from rop right
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool found = false;
        int i = 0, j = n-1;
        while(i < m && j >= 0) {
            if(matrix[i][j] == target) {
                found = true;
                break;
            }
            else if(matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return found;
    }
    */
    
    // Brute , traverse entire matrix
    // TC: O(m * n)
    // SC : O(1)
};