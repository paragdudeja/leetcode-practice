class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0, sum2 = 0;
        int n = nums1.size();
        for(int i = 0; i < n; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
        }
        
        int ans = sum1;
        int curr = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            curr += nums2[i] - nums1[i];
            mx = max(mx, curr);
            if(curr < 0) curr = 0;
        }
        
        ans = max(ans, sum1 + mx);
        
        curr = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            curr += nums1[i] - nums2[i];
            mx = max(mx, curr);
            if(curr < 0) curr = 0;
        }
        
        ans = max(ans, sum2 + mx);
        
        return ans;

    }
};