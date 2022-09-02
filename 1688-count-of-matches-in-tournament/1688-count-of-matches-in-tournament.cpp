class Solution {
public:
    int numberOfMatches(int n) {
        int match_count = 0;
        while(n > 1) {
            match_count += (n/2);
            n = (n+1)/2;
        }
        return match_count;
    }
};