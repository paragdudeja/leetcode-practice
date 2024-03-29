class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int start = 0;
        long long shortest = 1e7;
        long long sum = 0;
       
        deque<pair<long long, long long>> dq;
        
        for(long long i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(sum >= k) shortest = min(shortest, i+1);
            
            pair<long long, long long> curr = {INT_MIN, INT_MIN};
            
            while(!dq.empty() && sum - dq.front().second >= k) {
                curr = dq.front();
                dq.pop_front();
            }
            
            if(curr.second != INT_MIN) {
                shortest = min(shortest, i - curr.first);
            }
            
            while(!dq.empty() && sum <= dq.back().second) {
                dq.pop_back();
            }
            dq.push_back({i, sum});
        }
        
        return shortest == 1e7 ?  -1 : shortest;
        
    }
};