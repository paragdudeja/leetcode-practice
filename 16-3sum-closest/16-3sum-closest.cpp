class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        
        int diff = INT_MAX;
        int ans = -1;
        
        for(int first = 0; first < n; first++) {
            int second = first + 1;
            int third = n - 1;
            while(second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if(sum == target) {
                    return sum;
                }
                int currentDiff = abs(target - sum);
                if(currentDiff < diff) {
                    diff = currentDiff;
                    ans = sum;
                }
                if(sum < target) {
                    second++;
                }
                else {
                    third--;
                }
            }
        }
        return ans;
    }
};