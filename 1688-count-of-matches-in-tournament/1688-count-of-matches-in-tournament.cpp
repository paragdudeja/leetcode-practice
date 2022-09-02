class Solution {
public:
    int numberOfMatches(int n) {
        int match_count = 0;
        while(n > 1) {
            match_count += (n/2);
            if(n&1) {
                n = n/2 + 1;
            }
            else {
                n /= 2;
            }
        }
        return match_count;
    }
};