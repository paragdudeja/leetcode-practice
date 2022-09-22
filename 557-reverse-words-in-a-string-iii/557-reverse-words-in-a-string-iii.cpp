class Solution {
public:
    string reverseWords(string s) {
        int start = 0, n = s.size();
        for(int i = 0; i < n; ++i) {
            if(s[i] == ' ') {
                reverse_substr(s, start, i-1);
                start = i + 1;
            }
        }
        reverse_substr(s, start, n-1);
        return s;
    }
    
    void reverse_substr(string &s, int start, int end) {
        while(start < end) {
            swap(s[start++], s[end--]);
        }
    }
};