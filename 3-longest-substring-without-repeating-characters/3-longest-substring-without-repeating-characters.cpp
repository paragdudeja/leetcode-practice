class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
    /*
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
    */
};