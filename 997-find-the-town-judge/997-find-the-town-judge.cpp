class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n+1);
        
        for(auto &edge: trust) {
            int u = edge[0], v = edge[1];
            trusted[u]--;
            trusted[v]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(trusted[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};