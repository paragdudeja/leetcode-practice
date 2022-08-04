class Solution {
public:
    bool isValid(string s) {
        string curr;
        int len = 0;
        for(char &c: s) {
            curr.push_back(c);
            len++;
            if(len >= 3 && curr[len-3] == 'a' && curr[len-2] == 'b' && curr[len-1] == 'c') {
                len -= 3;
                curr.pop_back();
                curr.pop_back();
                curr.pop_back();
            }
        }
        
        return len == 0;
    }
};