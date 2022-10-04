class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
      int total = accumulate(nums.begin(), nums.end(), 0);
        int dp[21][21];
        memset(dp, -1, sizeof dp);
        int score = play(nums, 0, nums.size()-1, dp);
        return score >= (total+1)/2;
    }
    
    int play(vector<int>& nums, int i, int j, int dp[][21]){
        if(dp[i][j] != -1) return dp[i][j];
        if(i==j) return dp[i][j] = nums[i];
        if(i+1 == j) return dp[i][j] = max(nums[i], nums[j]);

        return dp[i][j] = max(nums[i] + min(play(nums, i+2, j, dp), play(nums, i+1, j-1, dp)),
                    nums[j] + min(play(nums, i+1, j-1, dp), play(nums, i, j-2, dp)));
    }
};