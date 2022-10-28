class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<int>> mp;
        
        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        
        for(auto it: mp) {
            vector<string> current;
            for(int idx: it.second)
                current.push_back(strs[idx]);
            result.push_back(current);
        }
        return result;
    }
};