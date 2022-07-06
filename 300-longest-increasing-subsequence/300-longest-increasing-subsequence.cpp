class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(const int &num: nums) {
            if(lis.empty() || lis.back() < num) {
                lis.push_back(num);
            }
            else {
                int idx = lowerBound(lis, num);
                lis[idx] = num;
            }
        }
        return lis.size();
    }
    
    int lowerBound(vector<int> &nums, int x) {
        int ans = nums.size();
        int low = 0, high = ans - 1;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};