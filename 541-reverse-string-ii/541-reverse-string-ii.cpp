class Solution {
public:
    string reverseStr(string s, int k) {
        bool flag = true;
        for(int i = 0; i < s.size(); i += k) {
            if(flag)
                reverse_substr(s, i, i+k-1);
            flag = !flag;
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