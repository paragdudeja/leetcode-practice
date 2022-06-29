class Solution {
public:
    int lps(int left, int right, string &s, int m, int &ans, vector<vector<int>> &dp) {
        //  Base cases
        if(left > right) return 0;
        if(left == right) return 1;
        
        if(dp[left][right] != -1) return dp[left][right];
        
        int res = 0;
        if(s[left] == s[right]) {
            res = 2 + lps(left + 1, right - 1, s, m, ans, dp);
            if(left < m && right >= m)
                ans = max(ans, res);
        }
        else
            res = max(lps(left+1, right, s, m, ans, dp), lps(left, right-1, s, m, ans, dp));
        
        return dp[left][right] = res;
    }
    
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size();
        int m = word1.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        lps(0, n-1, s, m, ans, dp);
        return ans;
    }
};