class Solution {
public:
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
};