class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<pair<long long, int>> room(n);
        
        sort(meetings.begin(), meetings.end());
        
        for(auto &meet: meetings) {
            long long start = meet[0];
            long long end = meet[1];
            bool scheduled = false;
            long long firstFree = LLONG_MAX;
            int idx = -1;
            
            for(int i = 0; i < n; ++i) {
                if(room[i].first <= start) {
                    room[i].first = end;
                    room[i].second++;
                    scheduled = true;
                    break;
                }
                else {
                    if(room[i].first < firstFree) {
                        firstFree = room[i].first;
                        idx = i;
                    }
                }
            }
            
            if(!scheduled) {
                long long duration = end - start;
                long long newend = room[idx].first + duration;
                room[idx].first = newend;
                room[idx].second++;
            }
        }
        
        int maxOccupiedId = 0;
        for(int i = 1; i < n; ++i) {
            if(room[i].second > room[maxOccupiedId].second) {
                maxOccupiedId = i;
            }
        }
        return maxOccupiedId;
    }
};