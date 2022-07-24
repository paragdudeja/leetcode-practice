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
        long long res = 0;
        unordered_set<int>s;
        vector<int>val;
        for(auto x:nums){
            if(s.count(x)) continue;
            val.push_back(countBit(x));
            s.insert(x);
        }
        sort(begin(val),end(val));
        for(auto x:val){
            auto it = end(val) - lower_bound(begin(val),end(val),k-x);
            res+= it;
        }
        
        return res;
    }
};