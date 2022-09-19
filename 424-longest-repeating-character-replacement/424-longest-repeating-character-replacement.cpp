class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 0;
        for(char ch = 'A'; ch <= 'Z'; ++ch) {
            longest = max(longest, longestRepeat(s, k, ch));
        }
        
        return longest;
    }
    
    int longestRepeat(string &s, int k, char ch) {
        int longest = 0;
        int current_length = 0;
        int start = 0;
        
        
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ch) {
                current_length++;
            }
            else {
                if(k > 0) {
                    k--;
                    current_length++;
                }
                else {
                    while(start <= i && s[start] == ch) {
                        start++;
                        current_length--;
                    }
                    start++;
                }
            }
            longest = max(longest, current_length);
        }
        return longest;
    }
};