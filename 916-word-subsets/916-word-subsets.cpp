class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> minCount(26);
        
        for(string &word: words2) {
            vector<int> currHash(26);
            for(char &ch: word) {
                currHash[ch - 'a']++;
            }
            
            for(int i = 0; i < 26; ++i) {
                minCount[i] = max(minCount[i], currHash[i]);
            }
        }
        
        for(string &word: words1) {
            vector<int> hash(26);
            for(char &ch: word) {
                hash[ch - 'a']++;
            }
            
            bool flag = true;
            for(int i = 0; i < 26; ++i) {
                if(hash[i] < minCount[i]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                result.push_back(word);
            }
        }
        return result;
    }
};