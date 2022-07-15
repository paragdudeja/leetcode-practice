class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int counter = 0;
        for(const char &c: s) {
            if(c == ' ') counter = 0;
            else ans = ++counter;
        }
        return ans;
    }
};