class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<vector<int>> mp(100002);
        int start = 0;
        
        for(vector<int> &prop: properties) {
            mp[prop[0]].push_back(prop[1]);
            start = max(start, prop[0]);
        }
        
        int rightMax = 0;
        
        int count = 0;
        for(int i = start; i >= 1; --i) {
            if(mp[i].empty()) continue;
            sort(mp[i].begin(), mp[i].end());
            int cnt = upper_bound(mp[i].begin(), mp[i].end(), rightMax-1) - mp[i].begin();
            count += cnt;
            rightMax = max(rightMax, mp[i].back());
        }
        
        return count;
    }
};