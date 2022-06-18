class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        long long t = target;
        
        for(int first = 0; first < nums.size(); first++){
            for(int second = first + 1; second < nums.size(); second++) {
                int third = second + 1;
                int fourth = nums.size() - 1;
                while(third < fourth) {
                    long long sum = (long long)nums[first] + nums[second] + nums[third] + nums[fourth];
                    if(sum == t) {
                        res.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                        while(third < fourth && nums[third]==nums[third+1]) third++;
                        while(third < fourth && nums[fourth]==nums[fourth-1]) fourth--;
                        third++;
                        fourth--;
                        
                    }
                    else if(sum < t)
                        third++;
                    else
                        fourth--;
                }
                while(second + 1 < nums.size() && nums[second]==nums[second+1]) second++;
            }
            while(first + 1 < nums.size() && nums[first]==nums[first+1]) first++;
        }
        return res;
    }
};