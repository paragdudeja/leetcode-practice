class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0) {
            return result;
        }
        
        vector<string> letters{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string current;
        helper(0, digits, letters, current, result);
        return result;
    }
    
    void helper(int index, string &digits, vector<string> &letters, string &current, vector<string> &result) {
        if(index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        for(char &ch: letters[digit]) {
            current.push_back(ch);
            helper(index + 1, digits, letters, current, result);
            current.pop_back();
        }
    }
};