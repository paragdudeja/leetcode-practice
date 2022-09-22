class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2*k) {
            reverse_substr(s, i, i+k-1);
        }
        return s;
    }
    
    void reverse_substr(string &s, int start, int end) {
        end = min(end, (int)s.size() - 1);
        while(start < end) {
            swap(s[start++], s[end--]);
        }
    }
};