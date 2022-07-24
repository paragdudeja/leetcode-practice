class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cuts(n);
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int j = 0; j < n; j++) {
            int minCuts = j;
            for(int i = 0; i <= j; i++) {
                if(s[j] == s[i] && (j - i < 3 || dp[i+1][j-1])) {
                    dp[i][j] = 1;
                    minCuts = i == 0 ? 0 : min(minCuts, cuts[i-1] + 1);
                }
            }
            cuts[j] = minCuts;
        }
        return cuts[n-1];
    }
    
    /*
    bool isPalindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    */
    
    /*
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1);
        dp[n] = 0;
        
        for(int i = n-1; i >= 0; --i) {
            int minCuts = INT_MAX;
            for(int j = i; j < n; ++j) {
                if(isPalindrome(s, i, j)) {
                    int cuts = 1 + dp[j+1];
                    minCuts = min(minCuts, cuts);
                }
            }

            dp[i] = minCuts;
        }
        
        return dp[0]-1;
    }
    */
    
    /*
    int solve(string &s, int i, int n, vector<int> &dp) {
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int minCuts = INT_MAX;
        for(int j = i; j < n; ++j) {
            if(isPalindrome(s, i, j)) {
                int cuts = 1 + solve(s, j+1, n, dp);
                minCuts = min(minCuts, cuts);
            }
        }
        
        return dp[i] = minCuts;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(s, 0, n, dp) - 1;
    }
    */
    
    /*
    int minCut(string s) {
        int n = s.size();
        vector<int> cuts(n);
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int i = 0; i < n; i++) {
            int minCuts = i;
            for(int j = 0; j <= i; j++) {
                dp[j][i] = s[j] == s[i] && (i - j < 3 || dp[j+1][i-1]);
                if(dp[j][i]) {
                    minCuts = j == 0 ? 0 : min(minCuts, cuts[j-1] + 1);
                }
            }
            cuts[i] = minCuts;
        }
        return cuts[n-1];
    }
    */
    
    /*
    int minCut(string s) {
        int n = s.size();
        vector<int> adj[n+1];
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int gap = 0; gap < n; gap++) {
            for(int i = 0, j = gap; j < n; i++, j++) {
                dp[i][j] = s[i] == s[j] && (gap < 2 || dp[i+1][j-1]);
                if(dp[i][j]) {
                    adj[i].push_back(j+1);
                }
            }
        }
        
        return bfs(adj, n);
    }
    
    int bfs(vector<int> adj[], int n) {
        vector<bool> vis(n+1);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int level = 0;
        
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                int node = q.front();
                q.pop();
                
                for(int dest: adj[node]) {
                    if(dest == n) return level;
                    if(!vis[dest]) {
                        q.push(dest);
                        vis[dest] = 1;
                    }
                }
            }
            level++;
        }
        return n;
    }
    */
};