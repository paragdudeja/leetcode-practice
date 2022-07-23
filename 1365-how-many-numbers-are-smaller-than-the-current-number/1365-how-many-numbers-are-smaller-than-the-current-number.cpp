class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        int temp[n];
        for(int i=0; i<n; i++) temp[i] = nums[i];
        sort(temp, temp+n);
        
        vector<int> cnt(n);
        for(int i=0; i<n; i++) {
            cnt[i] = lower_bound(temp, temp+n, nums[i]) - temp;
        }
        return cnt;
    }
};