class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(solve(nums, firstLen, secondLen), solve(nums, secondLen, firstLen));
    }
    
    int solve(vector<int>& A, int L, int M) {
        int n = A.size();
        int sMMax = 0;
        int sL = 0, sM = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            sL += A[i];
            if(i >= L) {
                sL -= A[i-L];
                sM += A[i-L];
            }
            if(i-L >= M) {
                sM -= A[i-L-M];
            }
            sMMax = max(sMMax, sM);
            res = max(res, sL + sMMax);      
        }
        
        return res;
    }
    
    /*
    // TC : O(N^2)
    // SC : O(N)
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        int prefix[n+1];
        prefix[0] = 0;
        for(int i = 0; i < n; ++i) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        
        int maxSum = 0;
        for(int i = firstLen; i <= n; ++i) {
            int firstSum = prefix[i] - prefix[i - firstLen];
            for(int j = i - firstLen; j - secondLen >= 0; --j) {
                int secondSum = prefix[j] - prefix[j - secondLen];
                maxSum = max(maxSum, firstSum + secondSum);
            }
            for(int j = n; j - secondLen >= i; j--) {
                int secondSum = prefix[j] - prefix[j - secondLen];
                maxSum = max(maxSum, firstSum + secondSum);
            }
        }
        return maxSum;
    }
    */
};