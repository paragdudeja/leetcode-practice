class Solution {
public:
    // TC : O(sqrt(N))
    // SC : O(1)
    int mySqrt(int x) {
        int ans = 1;
        while(ans <= x/ans) {
            ans++;
        }
        return ans - 1;
    }
};