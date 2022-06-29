// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    struct Interval {
        int startTime;
        int endTime;
        // Interval(startTime, endTime) : startTime(startTime), endTime(endTime) { }
    };
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<Interval> intervals(n);
        for(int i = 0; i < n; i++) {
            intervals[i] = {start[i], end[i]};
        }
        
        sort(intervals.begin(), intervals.end(), [](auto &interval1, auto &interval2){
            return interval1.endTime < interval2.endTime;
        });
        
        int cnt = 1;
        int last = intervals[0].endTime;
        for(int i = 1; i < n; i++) {
            if(intervals[i].startTime > last) {
                cnt++;
                last = intervals[i].endTime;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends