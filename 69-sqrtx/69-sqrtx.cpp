class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int low = 1, high = x,  ans = x;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(mid <= x/mid) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
    /*
    // TC : O(sqrt(N))
    // SC : O(1)
    int mySqrt(int x) {
        int ans = 1;
        while(ans <= x/ans) {
            ans++;
        }
        return ans - 1;
    }
    */
};