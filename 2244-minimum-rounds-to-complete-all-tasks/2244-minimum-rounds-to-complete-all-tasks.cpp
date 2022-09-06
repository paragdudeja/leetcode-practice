class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        
        for(int x: tasks) mp[x]++;
        
        int time = 0;
        for(auto it: mp) {
            if(it.second == 1) return -1;
            time += (it.second/3);
            // 7 / 3 = 2;
            if(it.second%3 != 0) time++;
        }
        return time;
    }
};