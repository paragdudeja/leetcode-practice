class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> available, vacant;
        for(int &x: nums) {
            available[x]++;
        }
        
        for(int &x: nums) {
            if(available[x] == 0) continue;
            
            if(vacant[x] > 0) {
                vacant[x]--;
                available[x]--;
                vacant[x+1]++;
            }
            else if(available[x+1]>0 && available[x+2]>0) {
                available[x]--;
                available[x+1]--;
                available[x+2]--;
                vacant[x+3]++;
            }
            else {
                return false;
            }
        }
        return true;
    }
    /*
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> s;
        for(int x: nums) {
            if(s[x-1].empty()) {
                s[x].push(1);
            }
            else {
                int len = s[x-1].top();
                s[x-1].pop();
                s[x].push(len+1);
            }
        }
        
        for(auto it: s) {
            while(!it.second.empty()) {
                if(it.second.top() < 3) return false;
                it.second.pop();
            }
        }
        return true;
    }
    */
    /*
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
    */
};