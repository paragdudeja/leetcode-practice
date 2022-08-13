class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        if(s.size() < len * words.size()) return vector<int>();
         
        unordered_map<string, int> mp;
        
        for(auto &word: words) {
            mp[word]++;
        }
        
        vector<int> ans;
        for(int i = 0; i <= s.size() - len * words.size(); ++i) {
            unordered_map<string, int> copy_map = mp;
            
            for(int j = 0; j < words.size(); ++j) {
                
                string sub = s.substr(i + j*len, len);
                if(copy_map.count(sub)) {
                    if(--copy_map[sub] == 0) {
                        copy_map.erase(sub);
                    }
                    if(copy_map.size() == 0) {
                        ans.push_back(i);
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};