class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int t = 1;
        string s = to_string(n);
        sort(s.begin(), s.end());
        bool flag = false;
        while(t > 0) {
            string tmp = to_string(t);
            sort(tmp.begin(), tmp.end());
            if(tmp == s) {
                flag = true;
                break;
            }
            else {
                t <<= 1;
            }
        }
        return flag;
        
    }
};