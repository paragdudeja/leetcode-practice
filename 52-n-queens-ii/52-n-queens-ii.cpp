class Solution {
public:
    int totalNQueens(int n) {
        string row;
        for(int i = 0; i < n; i++)
            row.push_back('.');
        vector<string> board;
        for(int i = 0; i < n; i++)
            board.push_back(row);
        return solve(0, n, board);
    }
    
    int solve(int col, int n, vector<string> &board) {
        if(col == n) {
            return 1;
        }
        
        int ans = 0;
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                ans += solve(col + 1, n, board);
                board[row][col] = '.';
            }
        }
        return ans;
    }
    
    bool isSafe(int row, int col, int n, vector<string> &board) {
        for(int j = 0; j < col; j++){
            if(board[row][j] == 'Q') {
                return false;
            }
        }
        
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        
        for(int i = row, j = col; i < n && j >= 0; i++, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
};