#define ll long long
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        ll ans=0;
        ll n=nums.size();
        for(ll i=n-2;i>=0;i--)
        {
            if(nums[i]<=nums[i+1])
                continue;
            ll val=nums[i]/nums[i+1];
            if(nums[i]%nums[i+1]==0)
                val--;
            nums[i]=nums[i]/(val+1);
            ans+=val;
        }
        return ans;
    }
};