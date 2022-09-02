class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        
        int rank = 1;
        unordered_map<int, int> mp;
        for(int x: tmp) {
            if(mp.count(x) == 0) mp[x] = rank++;
        }
        
        for(int &x: arr) {
            x = mp[x];
        }
        return arr;
    }
};