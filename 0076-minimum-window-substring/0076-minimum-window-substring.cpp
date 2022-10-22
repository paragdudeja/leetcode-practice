class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        vector<int> sfreq(256), tfreq(256);
        
        for(char &c: t)
            tfreq[c]++;
        
        int match_count = 0;
        int desired_match_count = t.size();
        
        int max_len = 0;
        int ans_left = -1, ans_right = -1;
        
        // cout << max_len << ans_left << ans_right;
        // cout << match_count << ' ' << desired_match_count << endl;
        
        int left = -1, right = -1;
        while(true) {
            bool flag1 = false, flag2 = false;
            // acquire
            // cout << right << ' ' << s.size() - 1 << endl;
            // cout << match_count << ' ' << desired_match_count << endl;
            // cout <<  ((right < (int)s.size() - 1) && (match_count < desired_match_count)) << endl;
            while((right < (int)s.size() - 1) && (match_count < desired_match_count)) {
                // cout << "Acquire\n";
                char ch = s[++right];
                // cout << ch << endl;
                sfreq[ch]++;
                if(sfreq[ch] <= tfreq[ch])
                    match_count++;
                flag1 = true;
            }
            
            // cout << right << endl;
            // release and collect ans;
            while(left < right && match_count == desired_match_count) {
                int len = right - left;
                if(max_len == 0 || len < max_len) {
                    max_len = len;
                    ans_left = left + 1;
                    ans_right = right;
                }
                char ch = s[++left];
                sfreq[ch]--;
                if(sfreq[ch] < tfreq[ch])
                    match_count--;
                flag2 = true;
            }
            
            if(!flag1 && !flag2) break;
        }
        return max_len == 0 ? "" : s.substr(ans_left, max_len); 
        
    }
};