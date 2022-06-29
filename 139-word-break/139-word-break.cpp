class Solution {
public:
    int dp[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());   
        memset(dp, -1, sizeof dp);
        return helper(0, s, wordSet);
    }
    
    bool helper(int index, string &s, unordered_set<string> &wordSet) {
        if(index == s.size())
            return true;
        
        if(dp[index] != -1) return dp[index];
        string word;
        for(int i = index; i < s.size(); i++) {
            word += s[i];
            if(wordSet.count(word) && helper(i+1, s, wordSet))
                return dp[index] = true;
        }
        return dp[index] = false;
    }
    
    
};