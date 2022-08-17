class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto &word: words) {
            string curr;
            for(auto &ch: word)
                curr  += morse[ch - 'a'];
            s.insert(curr);
        }
        return s.size();
    }
};