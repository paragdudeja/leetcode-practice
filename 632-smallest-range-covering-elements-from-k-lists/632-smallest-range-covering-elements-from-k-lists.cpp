class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        
        vector<int> ans{-100000, 100000};
        
        int mx = INT_MIN;
        int k = nums.size();
        for(int i = 0; i < k; ++i) {
            pq.push({nums[i][0], i, 0});
            mx = max(mx, nums[i][0]);
        }
        
        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int mn = curr[0], listid = curr[1], idx = curr[2];
            // cout << mx << ' ' << mn << endl;
            if((long long)mx - mn < (long long)ans[1] - ans[0]) {
                ans[0] = mn;
                ans[1] = mx;
            }
            if(idx == nums[listid].size() - 1) break;
            mx = max(mx, nums[listid][idx+1]);
            pq.push({nums[listid][idx+1], listid, idx+1});
        }
        return ans;
    }
};