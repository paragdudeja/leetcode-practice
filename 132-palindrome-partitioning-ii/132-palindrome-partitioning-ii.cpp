class Solution {
public:
    bool isPalindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    

    int solve (string & s, int i, int j, vector<vector<int>> & dp){    
        
        if(i>=j or isPalindrome(s, i, j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i; k<j; k++){
            
            /* 
                Instead of writing below standard line
                We will recurse for only right part
                Only when left part turns out to be palindrome
                
                int temp =  solve (s, i, k, dp, palindrome) + solve (s, k+1, j, dp, palindrome) + 1;
                
            */
            
            if(isPalindrome(s, i, k)){                         
                int temp = solve (s, k+1, j, dp) + 1;
                ans = min (ans, temp);
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
            
        return solve (s, 0, n-1, dp);
    }
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