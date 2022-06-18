class Solution {
public:
    int countLiveNeighbors(int i, int j, int m, int n, vector<vector<int>> &board) {
        int dx[8] = {1,-1,0,0,1,1,-1,-1};
        int dy[8] = {0,0,1,-1,1,-1,1,-1};
        
        int cnt = 0;
        for(int t=0; t<8; t++) {
            int x = i + dx[t];
            int y = j + dy[t];
            if(x>=0 && y>=0 && x<m && y<n && board[x][y] == 1)
                cnt++;
        }
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // vcetor<vector<int>> next(m, vector<int>(n));
        int next[m][n];
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int neigh = countLiveNeighbors(i, j, m, n, board);
                if(board[i][j] == 0){
                    if(neigh == 3)
                        next[i][j] = 1;
                    else next[i][j] = 0;
                }
                else {
                    if(neigh < 2 || neigh > 3)
                        next[i][j] = 0;
                    else
                        next[i][j] = 1;
                }
            }
        }
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                board[i][j] = next[i][j];
    }
};