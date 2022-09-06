class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            pq.push(nums[i]);
        }
        
        for(int i = 0; i < k; ++i) {
            int num = pq.top();
            pq.pop();
            
            int newnum = -num;
            sum = sum - num + newnum;
            pq.push(newnum);
        }
        
        return sum;
    }
};