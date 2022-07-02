class Solution {
public:
    int play(vector<int>& piles, int i, int j, int dp[][501]){
    if(dp[i][j] != -1) return dp[i][j];
        if(i==j) return dp[i][j] = piles[i];
        if(i+1 == j) return dp[i][j] = max(piles[i], piles[j]);

        return dp[i][j] = max(piles[i] + min(play(piles, i+2, j, dp), play(piles, i+1, j-1, dp)),
                    piles[j] + min(play(piles, i+1, j-1, dp), play(piles, i, j-2, dp)));
    }
    
    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(), piles.end(), 0);
        int dp[501][501];
        memset(dp, -1, sizeof dp);
        return play(piles, 0, piles.size()-1, dp) > total/2;
    }
};