class Solution {
public:
    bool isPossible(vector<int>& nums) {
        multiset<pair<int, int>> s;
        for(int x: nums) {
            auto it = s.lower_bound({x-1, 0});
            if(it == s.end() || it->first != (x-1)) {
                s.insert({x, 1});
            }
            else {
                s.insert({x, it->second+1});
                s.erase(it);
            }
        }
        
        for(auto it: s) {
            if(it.second < 3) return false;
        }
        return true;
    }
};