class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string row;
        for(int i = 0; i < n; i++)
            row.push_back('.');
        vector<string> board;
        for(int i = 0; i < n; i++)
            board.push_back(row);
        solve(0, n, board, result);
        return result;
    }
    
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
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