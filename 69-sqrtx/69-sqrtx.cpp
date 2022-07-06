class Solution {
public:
    int mySqrt(int x) {
        long long ans = 0;
        while(ans*ans <= x) {
            ans++;
        }
        return ans - 1;
    }
};