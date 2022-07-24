class Solution {
public:
    int countBit(int num){
        int res = 0;
        while(num){
            num &= (num - 1);
            res++;
        }
        return res;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long cnt[32] = {}, res = 0;
        unordered_set<int> s(begin(nums), end(nums));
        for (int n : s)
            ++cnt[countBit(n)];
        for (int i = 0; i < 32; ++i)
            for (int j = 0; j < 32; ++j)
                if(i + j >= k)
                    res += cnt[i] * cnt[j];
        return res;
    }
};