class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> result(n, -1);
        
        for(int i = 0; i < n; ++i) {
            intervals[i].push_back(i);
        }
        
        sort(intervals.begin(), intervals.end(), [](auto &i1, auto &i2){
            if(i1[0] == i2[0]) return i1[2] < i2[2];
            return i1[0] < i2[0];
        });
        
        for(int i = 0; i < n; ++i) {
            int idx = lowerBound(intervals, n, intervals[i][1]);
            if(idx < n)
                result[intervals[i][2]] = intervals[idx][2];
        }
        
        return result;
    }
    
    int lowerBound(vector<vector<int>> &intervals, int n, int end) {
        int low = 0, high = n-1, ans = n;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(intervals[mid][0] >= end) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};