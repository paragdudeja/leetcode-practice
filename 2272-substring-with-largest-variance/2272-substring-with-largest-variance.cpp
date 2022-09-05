class Solution {
public:
    int largestVariance(string s) {
        int max_variance = 0;
        
        for(char ch1 = 'a'; ch1 <= 'z'; ch1++) {
            for(char ch2 = 'a'; ch2 <= 'z'; ch2++) {
                if(ch1 == ch2) continue;
                for(int i = 0; i < 2; ++i) {
                    int f1 = 0, f2 = 0;
                    for(char ch: s) {
                        if(ch == ch1) f1++;
                        if(ch == ch2) f2++; 
                        if(f1 < f2) {
                            f1 = f2 = 0;
                        }
                        else if(f1 > 0 && f2 > 0) {
                            max_variance = max(max_variance, f1 - f2);
                        }
                    }
                    reverse(s.begin(), s.end());
                }
                
            }
        }
        
        return max_variance;
    }
};