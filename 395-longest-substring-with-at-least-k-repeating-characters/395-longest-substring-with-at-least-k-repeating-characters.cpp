class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        return solve(0, n-1, s, k);
    }
    
    int solve(int start, int end, string &s, int k) {
        // if(end - start + 1 < k) return 0;
        
        vector<int> freq(26);
        for(int i = start; i <= end; i++) {
            freq[s[i] - 'a']++;
        }
        
        for(int i = start; i <= end; i++) {
            if(freq[s[i] - 'a'] < k)
                return max(solve(start, i-1, s, k), solve(i+1, end, s, k));
        }
        return end - start + 1;
    }
};