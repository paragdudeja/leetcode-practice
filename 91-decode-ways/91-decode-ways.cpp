class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(101, -1);
        return solve(0, s, dp);
    }
    
    int solve(int idx, string &s, vector<int> &dp) {
        if(idx == s.size()) return 1;
        
        if(dp[idx] != -1) return dp[idx];
        
        int d1 = s[idx] - '0';
        if(d1 == 0) return 0;
        
        int ans = 0;
        ans += solve(idx + 1, s, dp);
        if(idx + 1 < s.size()) {
            int d2 = s[idx + 1] - '0';
            int num = d1 * 10 + d2;
            if(num <= 26) {
                ans += solve(idx+2, s, dp);    
            }
        }
        
        return dp[idx] = ans;
    }
};