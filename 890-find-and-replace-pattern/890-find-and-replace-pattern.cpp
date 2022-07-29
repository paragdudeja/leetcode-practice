class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for(string &word: words) {
            if(check(word, pattern)) {
                result.push_back(word);
            }
        }
        return result;
    }
    
    bool check(string &s, string &t) {
        if(s.size()!=t.size()) return false;
        vector<int> c(26, -100), d(26, -100);
        int n= s.size();
        for(int i=0; i<n; i++){
            int diff = s[i]-t[i];
            int index1 = s[i]-'a';
            int index2 = t[i]-'a';

            if(c[index1] == -100) c[index1] = diff;
            else if(c[index1]!=diff) return false;
            
            if(d[index2] == -100) d[index2] = diff;
            else if(d[index2]!=diff) return false;
        }
        return true;
    }
};