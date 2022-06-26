class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int index = 0, n = intervals.size();
        while(index < n && intervals[index][1] < newInterval[0])
            res.push_back(intervals[index++]);
        
        while(index < n && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        
        res.push_back(newInterval);
        
        while(index < n)
            res.push_back(intervals[index++]);
        
        return res;
    }
};