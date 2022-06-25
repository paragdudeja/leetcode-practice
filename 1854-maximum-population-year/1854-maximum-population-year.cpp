class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>  timeline(2052);
        for(auto &log: logs) {
            timeline[log[0]]++;
            timeline[log[1]]--;
        }
        
        for(int i = 1948; i <= 2051; i++) {
            timeline[i] += timeline[i-1];
        }
        
        int year = 0;
        int maxPopulation = 0;
        
        for(int i = 1948; i<= 2051; i++) {
            if(timeline[i] > maxPopulation) {
                maxPopulation = timeline[i];
                year = i;
            }
        }
        
        return year;
    }
};