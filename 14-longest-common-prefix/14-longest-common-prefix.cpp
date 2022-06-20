class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i;
        bool flag  = true;
        for(i = 0; i < strs[0].size(); i++) {
            for(const string &word: strs) {
                if(word.length() < i || word[i] != strs[0][i]) {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        return strs[0].substr(0, i);
    }
};