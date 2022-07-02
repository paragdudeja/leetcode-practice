class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        // if(a.length() > b.length()) r
        string tmp;
        int count = b.length() / a.length();
        for(int i = 0; i < count; i++) {
            tmp += a;
        }
        // cout << tmp << endl;
        if(tmp.find(b) != string::npos) return count;
        count++;
        tmp += a;
        if(tmp.find(b) != string::npos) return count;
        count++;
        tmp += a;
        if(tmp.find(b) != string::npos) return count;
        return -1;
    }
};