class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool seen[256] = {};
        int longest = 0;
        int start = 0;
        for(int end = 0; end < s.length(); end++) {
            while(seen[s[end]]) {
                seen[s[start++]] = false;
            }
            seen[s[end]] = true;
            longest = max(longest, end - start + 1);
        }
        return longest;
    }
};