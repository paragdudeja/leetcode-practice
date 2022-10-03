class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        
        int sum = neededTime[0], max_cost = sum;
        
        for(int i = 1; i < colors.size(); ++i) {
            if(colors[i] == colors[i-1]) {
                sum += neededTime[i];
                max_cost = max(max_cost, neededTime[i]);
            }
            else {
                cost += (sum - max_cost);
                sum = neededTime[i];
                max_cost = sum;
            }
        }
        cost += (sum - max_cost);
        return cost;
    }
};