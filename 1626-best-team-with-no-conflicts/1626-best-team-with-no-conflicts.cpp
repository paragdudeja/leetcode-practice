class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int ans = 0;
        int n = ages.size();
        int dp[n];
        
        vector<pair<int, int>> v;
        for(int i = 0; i < n; ++i) {
            v.push_back({ages[i], scores[i]});
        }
        
        sort(v.begin(), v.end(), [](pair<int, int> &p1, pair<int, int>&p2){
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        });
        
        for(int i = 0; i < n; ++i) {
            dp[i] = v[i].second;
            // cout << dp[i] << ' ';
            for(int j = 0; j < i; ++j) {
                if(v[j].first < v[i].first) { // lesser age
                    if(v[j].second <= v[i].second) {
                        dp[i] = max(dp[i], v[i].second + dp[j]);
                    }
                }
                else { // equal age
                    dp[i] = max(dp[i], dp[j] + v[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};