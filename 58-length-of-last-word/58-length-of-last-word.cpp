class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        stringstream ss(s);
        string word;
        while(ss >> word) {
            if(word.size()) ans = word.size();
        }
        return ans;
    }
};