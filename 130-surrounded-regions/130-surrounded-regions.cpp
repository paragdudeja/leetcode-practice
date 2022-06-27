class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            dfs(i, 0, m, n, board, 'V');
            dfs(i, n-1, m, n, board, 'V');
        }
        
        for(int j = 0; j < n; j++) {
            dfs(0, j, m, n, board, 'V');
            dfs(m-1, j, m, n, board, 'V');
        }
        
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                dfs(i, j, m, n, board, 'X');
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n ; j++) {
                if(board[i][j] == 'V') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board, char replacement) {
        if(i < 0 || j < 0 || i == m || j == n || board[i][j] != 'O') return;
        board[i][j] = replacement;
        dfs(i + 1, j, m, n, board, replacement);
        dfs(i - 1, j, m, n, board, replacement);
        dfs(i, j + 1, m, n, board, replacement);
        dfs(i, j - 1, m, n, board, replacement);
    }
};