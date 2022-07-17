class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int current = 0;
        int total = 0;
        
        for(int i = 0; i < gas.size(); i++) {
            int diff = (gas[i] - cost[i]);
            total += diff;
            current += diff;
            if(current < 0) {
                current = 0;
                start = i+1;
            }
        }
        return total >= 0 ? start : -1;
    }
};