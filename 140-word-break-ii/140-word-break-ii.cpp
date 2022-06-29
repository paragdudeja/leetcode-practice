class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> current;
        vector<string> result;
        helper(0, s, current, result, wordSet);
        return result;
    }
    
    void helper(int index, string &s, vector<string> &current, vector<string> &result, unordered_set<string> &dict) {
        if(index == s.size()) {
            string ans = current[0];
            for(int i = 1; i < current.size(); i++) {
                ans += " " + current[i];
            }
            result.push_back(ans);
            return;
        }
        
        string word;
        for(int i = index; i < s.size(); i++) {
            word.push_back(s[i]);
            if(dict.count(word)){
                current.push_back(word);
                helper(i + 1, s, current, result, dict);
                current.pop_back();
            }
        }
    }
};