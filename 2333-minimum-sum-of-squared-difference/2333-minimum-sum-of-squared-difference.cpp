class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> counts(100001);
        int mxDiff = 0;
        int n = nums1.size();
        for(int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            ++counts[diff];
            mxDiff = max(mxDiff, diff);
        }
        
        long long k = k1 + k2;
        for(int i = mxDiff; i > 0; --i) {
            if(k >= counts[i]) {
                k -= counts[i];
                counts[i-1] += counts[i];
                counts[i] = 0;
            }
            else {
                counts[i] -= k;
                counts[i-1] += k;
                k = 0;
                break;
            }
        }
        long long ans = 0;
        for(long long i = 1; i <= mxDiff; ++i) {
            ans += i*i * counts[i];
        }
        return ans;
    }
};