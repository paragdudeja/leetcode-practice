class Solution {
public:
    // TC : O(Log n)
    // SC : O(1)
    int mySqrt(int x) {
        if(x <= 1) return x;
        int low = 1, high = x;
        while(low < high) {
            int mid = low + (high - low)/2;
            if(mid > x/mid) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low - 1;
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