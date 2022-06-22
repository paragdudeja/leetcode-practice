class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() -1;
        while(i < j) {
            if(!isalnum(s[i])) {
                i++;
                continue;
            }
            if(!isalnum(s[j])) {
                j--;
                continue;
            }
            char left = s[i++];
            char right = s[j--];
            if(!isdigit(left) && left <= 'Z') left += 32;
            if(!isdigit(right) && right <= 'Z') right += 32;
            if(left != right) return false;
        }
        return true;
    }
};