class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        vector<vector<int>>  ans;
        
        for(int first = 0; first < nums.size(); first++) {
            int second = first + 1;
            int third = nums.size() - 1;
            int target = -nums[first];
            while(second < third) {
                int sum = nums[second] + nums[third];
                if(sum == target)  {
                    ans.push_back({nums[first], nums[second], nums[third]});
                    while(second < third && nums[second] == nums[second+1]) second++;
                    while(second < third && nums[third] == nums[third-1]) third--;
                    second++;
                    third--;
                }
                else if(sum > target) third--;
                else second++;
                
            }
            while(first + 1 < nums.size() && nums[first] == nums[first+1]) first++;
        }
        return ans;
    }
};