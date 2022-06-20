class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int diff = INT_MAX;
        int ans = -1;
        for(int first = 0; first < n; first++) {
            int second = first + 1;
            int third = n - 1;
            while(second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if(sum == target) {
                    diff = 0;
                    ans = sum;
                    while(second < third && nums[second] == nums[second+1]) second++;
                    while(second < third && nums[third] == nums[third-1]) third--;
                    second++;
                    third--;
                }
                else if(sum < target) {
                    if(target - sum < diff) {
                        diff = target - sum;
                        ans = sum;
                    }
                    second++;
                }
                else {
                    if(sum - target < diff) {
                        diff = sum - target;
                        ans = sum;
                    }
                    third--;
                }
            }
            while(first+1 < n && nums[first] == nums[first+1]) first++;
        }
        
        return ans;
    }
};