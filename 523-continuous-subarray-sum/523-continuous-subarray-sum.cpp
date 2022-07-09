class Solution {
public:
    // TC : O(N)
    // SC : O(1) 
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remainder = sum % k;
            if(mp.find(remainder) == mp.end()) {
                mp[remainder] = i;
            }
            else if(i - mp[remainder] > 1) {
                return true;
            }
        }
        return false;
    }
    
    /*
    Brute, all subarrays
    TC : O(N^2)
    SC : O(1) 
    */
};