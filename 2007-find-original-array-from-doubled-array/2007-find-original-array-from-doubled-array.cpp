class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> original;
        
        unordered_map<int, int> mp;
        for(int &num: changed) {
            mp[num]++;
        }
        
        sort(changed.rbegin(), changed.rend());
        for(int &num: changed) {
            if(num == 0) {
                if(mp[0] & 1) {
                    return {};
                }
                else {
                    for(int i = 0; i < mp[0]/2; ++i) {
                        original.push_back(0);        
                    }
                    break;
                }
            }
            else {
                if(mp[num] == 0) continue;
                if(num%2 == 0 && mp.count(num/2) && mp[num/2] > 0) {
                    mp[num]--;
                    mp[num/2]--;
                    original.push_back(num/2);
                }
                else {
                    return {};
                }
            }
        }
        return original;
    }
};