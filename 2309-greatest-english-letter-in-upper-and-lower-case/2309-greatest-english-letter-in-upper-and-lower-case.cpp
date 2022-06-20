class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> low(128);
        for(char &c: s) {
            low[c] = 1;
        }
        string ans;
        for(int i = 122; i >= 97; i--) {
            if(low[i] && low[i - 32]) {
                ans.push_back((char)(i-32));
                break;
            }
        }
        return ans;
    }
};