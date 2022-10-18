class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; ++i) {
            string curr;

            int cnt = 1;
            for(int j = 1; j < ans.size(); ++j) {
                if(ans[j] == ans[j-1]) {
                    cnt++;
                }
                else {
                    curr += to_string(cnt);
                    curr.push_back(ans[j-1]);
                    cnt = 1;
                }
            }
            curr += to_string(cnt);
            curr.push_back(ans.back());

            // cout << curr << endl;

            ans = curr;
        }
        return ans;
    }    
    
    /*
    string countAndSay(int n) {
        string ans = solve(n);
        ans.pop_back();
        return ans;
    }
    
    string solve(int n) {
        if(n == 1)
            return "1#";
        string prev = solve(n - 1);
        string tmp;
        int cnt = 1;
        for(int i = 1; i < prev.size(); i++) {
            if(prev[i] == prev[i-1]) cnt++;
            else {
                tmp += to_string(cnt);
                tmp.push_back(prev[i-1]);
                cnt = 1;
            }
        }
        tmp.push_back('#');
        return tmp;
    }
    */
};