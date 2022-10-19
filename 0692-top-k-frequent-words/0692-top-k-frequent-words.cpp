struct myOperator {
    bool operator()(pair<int, string> &p1, pair<int, string> &p2) {
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    } 
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto &word: words) {
            mp[word]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, myOperator> pq;    
        for(auto it: mp) {
            pq.push({it.second, it.first});
        }
        
        vector<string> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};