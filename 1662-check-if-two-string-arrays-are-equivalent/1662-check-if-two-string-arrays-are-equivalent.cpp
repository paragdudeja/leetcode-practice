class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for(const string &s: word1) 
            for(const char &ch: s) 
                s1.push_back(ch);

        for(const string &s: word2) 
            for(const char &ch: s) 
                s2.push_back(ch);
            
        
        return s1 == s2;
    }
};