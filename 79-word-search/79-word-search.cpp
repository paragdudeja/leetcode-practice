class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int i, int j, int idx, vector<vector<char>> &board, string &word) {
        if(idx == word.size()) {
            return true;
        }
        
        if(i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != word[idx]) {
            return false;
        }
        
        board[i][j] = '#';
        if(dfs(i+1, j, idx+1, board, word) || dfs(i, j+1, idx+1, board, word)
          || dfs(i-1, j, idx+1, board, word) || dfs(i, j-1, idx+1, board, word)) {
            return true;
        }
        board[i][j] = word[idx];
        return false;
    }
};