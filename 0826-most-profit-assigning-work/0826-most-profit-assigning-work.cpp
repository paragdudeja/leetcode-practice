class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> data;
        int n = profit.size();
        for(int i = 0; i < n; ++i) {
            data.push_back({difficulty[i], profit[i]});
        }
        sort(data.begin(), data.end());
        
        for(int i = 1; i < n; ++i) {
            data[i].second = max(data[i].second, data[i-1].second);
        }
        
        int idx = 0;
        int total_profit = 0;
        sort(worker.begin(), worker.end());
        for(int &w: worker) {
            while(idx < n && data[idx].first <= w) 
                idx++;
            
            if(idx > 0) 
                total_profit += data[idx-1].second;
        }
        return total_profit;
    }
    
    /*
    TC : O(N^2) 
    SC : O(1)
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int total_profit = 0;
        int n = profit.size();
        for(int &q: worker) {
            int current_profit = 0;
            for(int i = 0; i < n; ++i) {
                if(difficulty[i] <= q) {
                    current_profit = max(current_profit, profit[i]);
                }
            }
            total_profit += current_profit;
        }
        return total_profit;
    }
    */
};