class Solution {
public:
    int dp[21][31];
    bool solve(string &s, string &p, int i, int j) {
        // cout << i << ' ' << j << endl;
        if(i == -1 && j == -1) return true;
        if(i == -1) {
            for(int k = j; k >= 0; k -= 2) {
                if(p[k] != '*') return 0;
            }
            return 1;
        }
        if(j == -1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(p[j] == '*') {
            if(p[j-1] == '.' ||  s[i] == p[j-1]) {
                return dp[i][j] = solve(s, p, i-1, j) or solve(s, p, i, j-2);
            }
            else {
                return dp[i][j] = solve(s, p, i, j-2);
            }
        }
        if(p[j] == '.' || s[i] == p[j]) 
            return dp[i][j] = solve(s, p, i-1, j-1);
        return dp[i][j] = 0;
    }
    
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof dp);
        return solve(s, p, s.size()-1, p.size()-1);
    }
};