class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = INT_MAX;
        
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        // cout << low << ' ' << high << endl;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(isPossible(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    bool isPossible(vector<int> &weights, int days, int curr_max_weight) {
        int days_count = 1;
        int curr_weight = 0;
        for(int &weight: weights) {
            if(curr_weight + weight > curr_max_weight) {
                curr_weight = weight;
                days_count++;
            }
            else {
                curr_weight += weight;
            }
            
            
            if(days_count > days) break;;
        }
        // cout << curr_max_weight << ' ' << days_count << endl;
        return days_count <= days;
    }
};