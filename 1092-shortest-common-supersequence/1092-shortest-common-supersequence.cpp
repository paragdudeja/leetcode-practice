class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int dp[n+1][m+1];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // cout << dp[n][m] << endl;
        // cout << (m + n - dp[n][m] )<< endl;
        string ans = "";
        int i = n, j = m;
        while(i > 0 && j > 0 ) {
            if(str1[i-1] == str2[j-1]) {
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans += str1[i-1];
                i--;
            }
            else {
                ans += str2[j-1];
                j--;
            }
        }
        while(i > 0) {
            ans += str1[i-1];
            i--;
        }
        while(j > 0) {
            ans += str2[j-1];
                j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};