class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        for(auto &interval: intervals) {
            if(res.empty() || interval[0] > res.back()[1])
                res.push_back(interval);
            else
                res.back()[1] = max(res.back()[1], interval[1]);
        }
        return res;
    }
};