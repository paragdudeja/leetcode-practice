class Solution {
public:
    int largestVariance(string s) {
        string r = s;
        reverse(s.begin(), s.end());
        
        vector<int> freq(256);
        for(char &ch: s) freq[ch]++;
        
        return max(get_max_var(s, freq), get_max_var(r, freq));
    }
    
    int get_max_var(string &s, vector<int> &freq) {
        int max_variance = 0;
        for(char ch1 = 'a'; ch1 <= 'z'; ch1++) {
            for(char ch2 = 'a'; ch2 <= 'z'; ch2++) {
                if(ch1 == ch2 || freq[ch1] == 0 || freq[ch2] == 0) continue;
                int f1 = 0, f2 = 0;
                for(char &ch: s) {
                    if(ch == ch1) f1++;
                    if(ch == ch2) f2++; 
                    if(f1 < f2) {
                        f1 = f2 = 0;
                    }
                    else if(f1 > 0 && f2 > 0) {
                        max_variance = max(max_variance, f1 - f2);
                    }
                }
            }
        }
        return max_variance;
    }
};