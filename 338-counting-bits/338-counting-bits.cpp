class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> setbitCount(n + 1);
        for(int i = 1; i <= n; i++) {
            setbitCount[i] = setbitCount[i>>1] + (i&1);
        }
        return setbitCount;
    }
};