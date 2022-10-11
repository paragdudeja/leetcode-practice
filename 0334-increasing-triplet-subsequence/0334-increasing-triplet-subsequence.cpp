class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> v;
        for(auto x: nums) {
            if(v.empty() || x > v.back()) {
                v.push_back(x);
            }
            else {
                int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
                v[idx] = x;
            }
            if(v.size() == 3) break;
        }
        return v.size() == 3;
    }
};