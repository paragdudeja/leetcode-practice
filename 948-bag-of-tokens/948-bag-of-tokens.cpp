class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int largestScore = 0;
        
        sort(tokens.begin(), tokens.end());
        
        int min_ptr = 0, max_ptr = tokens.size()-1;
        while(min_ptr <= max_ptr) {
            if(tokens[min_ptr] <= power) {
                power -= tokens[min_ptr];
                ++score;
                ++min_ptr;
            }
            else if(score > 0) {
                score--;
                power += tokens[max_ptr];
                --max_ptr;
            }
            else {
                break;
            }
            largestScore = max(largestScore, score);
        }
        
        return largestScore;
    }
};