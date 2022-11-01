class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        
        for(int k = 0; k < n; ++k) {            
            int j = k, i = 0;
            bool stuck = false;
            while(i < m) {
                if(j+1 < n && grid[i][j] == 1 && grid[i][j+1] == 1) {
                    j++;
                }
                else if(j > 0 && grid[i][j] == -1 && grid[i][j-1] == -1) {
                    j--;
                }
                else {
                    stuck = true;
                    break;
                }
                i++;
            }
            
            if(!stuck) ans[k] = j;
        }
        
        return ans;
    }
};