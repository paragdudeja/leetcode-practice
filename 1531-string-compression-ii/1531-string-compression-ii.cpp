class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        
        if(n == 100) {
            bool all_same = true;
            for(int i = 1; i < 100; ++i) {
                if(s[i] != s[i-1]) {
                    all_same = false;
                    break;
                }
            }
            if(all_same) return 4;
        }
        
        // vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(27, 
        //         vector<vector<int>>()))
        // (current freq, previous, current freq, k)
        int dp[102][28][12][102];
        // memset(dp, sizeof dp, -1);
        
        for(int i = 0; i < 102; ++i) {
            for(int j = 0; j < 28; ++j) {
                for(int k = 0; k < 12; ++k) {
                    for(int l = 0; l < 102; ++l) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        
        return solve(0, 26, 0, k, s, dp);
    }
    
    int solve(int idx, int prev, int freq, int k, string &s, int dp[102][28][12][102]) {
        if(k < 0) return 1e9;
        
        if(idx == s.size()) {
            return 0;
        }
        
        if(dp[idx][prev][freq][k] != -1)
            return dp[idx][prev][freq][k];
        
        if(freq >= 10) {
            freq = 10;
        }
        
        
        int result = 1e9;
        
        // Skip
        result = min(result, solve(idx+1, prev, freq, k-1, s, dp));
        
        
        // Pick
        // -- check prev
        
        if(prev != (s[idx] - 'a')) {
            result = min(result, 1 + solve(idx+1, s[idx] - 'a', 1, k, s, dp));
        }
        else {
            if(freq == 1 || freq == 9) {
                result = min(result, 1 + solve(idx+1, s[idx] - 'a', freq+1, k, s, dp));
            }
            else {
                result = min(result, solve(idx+1, s[idx] - 'a', freq+1, k, s, dp));
            }
        }
        
        return dp[idx][prev][freq][k] = result;
    }
};