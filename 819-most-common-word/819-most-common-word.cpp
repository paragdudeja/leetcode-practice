class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> dont_care(banned.begin(), banned.end());
        unordered_map<string, int> frequency;
        
        string word;
        for(char &ch: paragraph) {
            if(isalpha(ch)) {
                if(ch <= 'Z') {
                    ch += 32;
                }
                word.push_back((char)ch);
            }
            else if(word.size() > 0) {
                if(dont_care.count(word) == 0) {
                    frequency[word]++;
                }
                word = "";
            }
        }
        if(word.size() > 0 && dont_care.count(word) == 0) {
            frequency[word]++;
        }
        word = "";
        int maxFreq = 0;
        for(auto it: frequency) {
            if(it.second > maxFreq) {
                maxFreq = it.second;
                word = it.first;
            }
        }
        return word;
    }
};