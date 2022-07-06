class Solution {
public:
    // TC : O(N^2)
    // SC : O(N^2)
    int countSubstrings(string s) {
        int n = s.size();
        bool dp[n][n];
        int count = 0;
        for(int gap = 0; gap < n; gap++) {
            for(int i = 0, j = gap; j < n; i++, j++) {
                if(gap == 0)
                    dp[i][j] = 1;
                else if(gap == 1)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
                count += dp[i][j];
            }
        }
        return count;
    }
};