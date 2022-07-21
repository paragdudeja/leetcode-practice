class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        
        int prefix[n+1];
        prefix[0] = 0;
        for(int i = 0; i < n; ++i) {
            prefix[i+1] = prefix[i] + nums[i];
            // cout << prefix[i+1] << ' ';
        }
        
        int maxSum = 0;
        for(int i = firstLen; i <= n; ++i) {
            // cout << firstLen << ' ' << (firstLen-i) << endl;
            int firstSum = prefix[i] - prefix[i - firstLen];
            // cout << firstSum << endl;

            for(int j = i - firstLen; j - secondLen >= 0; --j) {
                int secondSum = prefix[j] - prefix[j - secondLen];
                maxSum = max(maxSum, firstSum + secondSum);
                // cout << secondSum << ' ';
            }
            // cout << endl;
            for(int j = n; j - secondLen >= i; j--) {
                int secondSum = prefix[j] - prefix[j - secondLen];
                maxSum = max(maxSum, firstSum + secondSum);
            }
        }
        return maxSum;
    }
};