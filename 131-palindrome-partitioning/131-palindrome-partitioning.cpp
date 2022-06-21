class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        helper(0, s, current, result);
        return result;
    }
    
    void helper(int start, string &s, vector<string> &current, vector<vector<string>> &result) {
        if(start == s.size()) {
            result.push_back(current);
            return;
        }
        
        for(int end = start; end < s.size(); end++) {
            if(isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                helper(end + 1, s, current, result);
                current.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};