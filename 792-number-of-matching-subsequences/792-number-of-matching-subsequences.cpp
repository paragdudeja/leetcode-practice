class Solution {
public:    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        int n = s.size();
        
        vector<vector<int>> pos(26);
        
        for(int i=0;i<n;i++)
            pos[s[i]-'a'].push_back(i);
        
        for(const string &word:words) {
            int idx = 0;
            bool flag = 1;
            for(const char &ch: word) {
                auto currIdx = lower_bound(pos[ch-'a'].begin(), pos[ch-'a'].end(), idx);
                if(currIdx == pos[ch-'a'].end()) {
                    flag = 0;
                    break;
                }
                idx = *currIdx+1;
            }
            
            if(flag) ++count;
        }
        return count;
    }
};
