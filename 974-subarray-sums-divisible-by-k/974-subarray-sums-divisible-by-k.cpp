class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> rem(k);
        rem[0] = 1;
        
        int ans = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remainder = sum%k;
            if(remainder < 0) remainder += k;
            ans += rem[remainder];
            rem[remainder]++;
        }
        return ans;
    }
};