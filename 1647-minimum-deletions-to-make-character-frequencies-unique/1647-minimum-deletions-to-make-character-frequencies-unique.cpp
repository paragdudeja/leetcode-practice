class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        unordered_set<int> seen;
        
        for(char &c: s) {
            freq[c - 'a']++;
        }
        
        sort(freq.begin(), freq.end(), greater<int>());
        int deletions = 0;
        
        for(int &cnt: freq) {
            while(cnt > 0 && seen.find(cnt) != seen.end()) {
                cnt--;
                deletions++;
            }
            seen.insert(cnt);
        }
        return deletions;
        
    }
};