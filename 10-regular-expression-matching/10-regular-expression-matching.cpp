class Solution {
public:
    bool solve(string &s, string &p, int i, int j) {
        cout << i << ' ' << j << endl;
        if(i == -1 && j == -1) return true;
        if(i == -1) {
            for(int k = j; k >= 0; k -= 2) {
                if(p[k] != '*') return 0;
            }
            // cout << "Yes\n";
            return 1;
        }
        if(j == -1) return 0;
        
        if(p[j] == '*') {
            if(p[j-1] == '.' ||  s[i] == p[j-1]) {
                return solve(s, p, i-1, j) or solve(s, p, i, j-2);
            }
            else {
                return solve(s, p, i, j-2);
            }
        }
        if(p[j] == '.' || s[i] == p[j]) 
            return solve(s, p, i-1, j-1);
        return 0;
    }
    
    bool isMatch(string s, string p) {
        return solve(s, p, s.size()-1, p.size()-1);
    }
};