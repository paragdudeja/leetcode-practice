class Solution {
public:
    string reverseOnlyLetters(string s) {
        string letters;
        for(char &c: s) {
            if(isalpha(c)) {
                letters.push_back(c);
            }
        }
        reverse(letters.begin(), letters.end());
        
        int k = 0;
        for(char &c: s) {
            if(isalpha(c)) {
                c = letters[k++];
            }
        }
        return s;
    }
};