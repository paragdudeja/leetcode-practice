class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        map<int, vector<int>> mp;
        int start = 0;
        
        for(vector<int> &prop: properties) {
            mp[prop[0]].push_back(prop[1]);
        }
        
        int rightMax = 0;
        
        int count = 0;
        for(auto it = mp.rbegin(); it != mp.rend(); ++it) {
            int mx = 0;
            for(auto &x: it->second) {
                if(x < rightMax) ++count;
                mx = max(mx, x);
            }
            rightMax = max(mx, rightMax);
        }
        
        return count;
    }
};