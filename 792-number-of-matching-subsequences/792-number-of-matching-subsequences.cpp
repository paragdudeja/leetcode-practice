class Solution {
public:
    bool hasMatches(string &curr, string &s) {
        int pos = 1;
        int i = s.find(curr[0]);
        if (i == -1)
            return false;
        while (pos < curr.length()) {
            i = s.find(curr[pos], i + 1);
            if (i == -1)
                return false;
            pos++;
        }
        return true;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for (string str : words)
            if (hasMatches(str, s))
                count++;
        
        return count;
    }
};
