class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        
        int ans;
        while(low < high) {
            int mid = low + (high-low)/2;
            int rank = getRank(mid, matrix);
            if(rank < k) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
    
    int getRank(int num, vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int count = 0;
        int i = m-1, j = 0;
        while(i >= 0 && j < n) {
            if(num < matrix[i][j]) {
                i--;
            }
            else {
                count += i+1;
                j++;
            }
        }
        return count;
    }
};