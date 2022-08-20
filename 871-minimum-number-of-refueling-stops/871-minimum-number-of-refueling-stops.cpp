class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int maxReach = startFuel;
        int n = stations.size();
        int used = 0;
        
        int index = 0;
        while(true) {
            if(maxReach >= target) break;
            while(index < n && stations[index][0] <= maxReach) {
                pq.push(stations[index][1]);
                index++;
            }
            
            if(pq.empty()) return -1;
            
            maxReach += pq.top();
            pq.pop();
            used++;
        }
        return used;
    }
};