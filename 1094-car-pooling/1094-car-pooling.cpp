class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int timeline[1001] = {};
        
        for(auto trip: trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            
            timeline[from] += numPassengers;
            timeline[to] -= numPassengers;
        }
        
        for(int i=0; i<= 1000; i++) {
            capacity -= timeline[i];
            if(capacity < 0) return false;
        }
        return true;
        return true;
    }
};