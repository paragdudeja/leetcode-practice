class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            dfs(i, 0, m, n, board);
            dfs(i, n-1, m, n, board);
        }
        
        for(int j = 0; j < n; j++) {
            dfs(0, j, m, n, board);
            dfs(m-1, j, m, n, board);
        }
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n ; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'V') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board) {
        if(i < 0 || j < 0 || i == m || j == n || board[i][j] != 'O') return;
        board[i][j] = 'V';
        dfs(i + 1, j, m, n, board);
        dfs(i - 1, j, m, n, board);
        dfs(i, j + 1, m, n, board);
        dfs(i, j - 1, m, n, board);
    }
};