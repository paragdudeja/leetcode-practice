class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums[0];
        priority_queue<pair<int, int>> pq; // {score, index};
        pq.push({nums[0], 0});
        
        for(int i = 1; i < nums.size(); i++) {
            while(!pq.empty() && i - pq.top().second > k) {
                pq.pop();
            }
            int sum = pq.top().first + nums[i];
            if(i == nums.size() - 1) return sum;
            pq.push({sum, i});
        }
        return 0;
    }
};