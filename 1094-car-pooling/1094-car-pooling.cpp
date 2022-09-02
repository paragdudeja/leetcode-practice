class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int timeline[1002] = {};
        
        for(auto trip: trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            
            timeline[from] += numPassengers;
            timeline[to] -= numPassengers;
        }
        
        for(int i = 1; i <= 1001; ++i) {
            timeline[i] += timeline[i-1];
        }
        
        for(int i = 0; i <= 1001; ++i) {
            if(timeline[i] > capacity) return false;
        }
        return true;
    }
};