class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> index;
        int n = target.size();
        string s;
        for(int i = 0; i < n; ++i) {
            s.push_back('?');
        }
        
        while(s != target) {
            int idx = getStampIndex(target, stamp);
            if(idx == -1) {
                return vector<int>();
            }
            else {
                index.push_back(idx);
                for(int i = 0; i < stamp.size(); ++i) {
                    target[i + idx] = '?';
                }
            }
        }
        
        reverse(index.begin(), index.end());        
        return index;
    }
    
    int getStampIndex(string &target, string &stamp) {
        int idx = -1;
        for(int i = 0; i <= target.size() - stamp.size(); ++i) {
            int j = 0, k = i;
            bool flag = false;
            while(j < stamp.size() && k < target.size() && (target[k] == '?' || target[k] == stamp[j])) {
                if(target[k] != '?') {
                    flag = true;
                }
                ++j; 
                ++k;
            }
            if(flag && j == stamp.size()) {
                idx = i;
                break;
            }
        }
        return idx;
    }
};