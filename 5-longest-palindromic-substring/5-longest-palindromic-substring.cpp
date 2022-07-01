class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int longest = 0;
        int start = 0;
        
        for(int gap = 0; gap < n; gap++) {
            for(int i = 0, j = gap; j < n; i++, j++) {
                if(gap == 0)
                    dp[i][j] = 1;
                else if(gap == 1)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = s[i] == s[j] && dp[i+1][j-1] == 1;
                if(dp[i][j] && j-i+1 > longest) {
                    start = i;
                    longest = j-i+1;
                }
            }
        }
        return s.substr(start, longest);
    }
};