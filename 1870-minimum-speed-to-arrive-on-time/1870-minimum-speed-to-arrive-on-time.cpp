class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        // if((double)n > hour) return -1;
        int low = 1, high = *max_element(dist.begin(), dist.end()) * 100;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            double time = 0;
            for(int i = 0; i < n-1; ++i) {
                time += ceil((double)dist[i]/mid);
            }
            time += (double)dist.back()/mid;
            cout << time << ' ' << mid << endl;
            if(time <= hour) {
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