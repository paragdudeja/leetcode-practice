class Solution {
public:
    int mySqrt(int x) {
        int ans = 1;
        while(ans <= x/ans) {
            ans++;
        }
        return ans - 1;
    }
};