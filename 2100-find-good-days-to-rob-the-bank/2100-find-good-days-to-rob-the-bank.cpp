class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> prev(n), next(n);
        prev[0] = 0;
        for(int i = 1; i < n; ++i) {
            if(security[i] > security[i-1]) {
                prev[i] = 0;
            }
            else {
                prev[i] = prev[i-1] + 1;
            }
            // cout << prev[i] << ' ';
        }
        // for(int p: prev) {
        //     cout << p << ' ';
        // }
        // cout << endl;
        
        next[n-1] = 0;
        for(int i = n-2; i >= 0; --i) {
            if(security[i] > security[i+1]) {
                next[i] = 0;
            }
            else {
                next[i] = next[i+1] + 1;
            }
        }
        // for(int p: next) {
        //     cout << p << ' ';
        // }
        
        vector<int> ans;
        for(int i = time; i < n - time; ++i) {
            if(prev[i] >= time && next[i] >= time) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    /*
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ans;
        int n = security.size();
        for(int i = time; i < n - time; ++i) {
            bool flag = true;
            for(int j = i - time; j < i; ++j) {
                if(security[j] < security[j+1]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                for(int j = i; j < i+time; ++j) {
                    if(security[j] > security[j+1]) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
    */
};