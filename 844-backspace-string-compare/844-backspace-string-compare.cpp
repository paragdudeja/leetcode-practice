class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return getStringAFterBackSpace(s) == getStringAFterBackSpace(t);
    }
    
    string getStringAFterBackSpace(string &str) {
        string ans;
        for(char &c: str) {
            if(c == '#') {
                if(!ans.empty()) {
                    ans.pop_back();
                }
            }
            else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};