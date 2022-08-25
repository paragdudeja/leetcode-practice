class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash1(26), hash2(26);
        for(char &ch: ransomNote) {
            hash1[ch - 'a']++;
        }
        
        for(char &ch: magazine) {
            hash2[ch - 'a']++;
        }
        
        for(int i = 0; i < 26; ++i) {
            if(hash1[i] > hash2[i]) {
                return false;
            }
        }
        
        return true;
    }
};