class Solution {
public:
    // TC : O(N * |strs[0|)
    // SC : O(N)
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; i < strs[0].size(); i++) {
            for(const string &word: strs) {
                if(word.length() <= i || word[i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};