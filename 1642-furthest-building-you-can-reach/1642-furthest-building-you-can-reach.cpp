class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i] - heights[i+1];
            if(diff >= 0) continue;
            pq.push(-diff);
            // cout << diff << endl;
            if(pq.size() > ladders) {
                if(pq.top() <= bricks) {
                    bricks -= pq.top();
                    pq.pop();
                }
                else {
                    return i;
                }
            } 
        }
        return (int)heights.size() - 1;
    }
};