class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n));
        return solve(0, n, board);
    }
    
    int solve(int col, int n, vector<vector<bool>> &board) {
        if(col == n) {
            return 1;
        }
        
        int ans = 0;
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, n, board)) {
                board[row][col] = 1;
                ans += solve(col + 1, n, board);
                board[row][col] = 0;
            }
        }
        return ans;
    }
    
    bool isSafe(int row, int col, int n, vector<vector<bool>> &board) {
        for(int j = 0; j < col; j++){
            if(board[row][j]) {
                return false;
            }
        }
        
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j]) {
                return false;
            }
        }
        
        for(int i = row, j = col; i < n && j >= 0; i++, j--) {
            if(board[i][j]) {
                return false;
            }
        }
        
        return true;
    }
};