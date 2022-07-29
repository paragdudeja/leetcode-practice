class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> c(256, -100), d(256, -100);
        int n= s.size();
        for(int i=0; i<n; i++){
            int index1 = s[i];
            int index2 = t[i];
            int diff = index1-index2;

            if(c[index1] == -100) c[index1] = diff;
            else if(c[index1]!=diff) return false;
            
            if(d[index2] == -100) d[index2] = diff;
            else if(d[index2]!=diff) return false;
        }
        return true;
    }
};