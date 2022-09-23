class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 1;
        for(int i = 2; i <= n; ++i) {
            int k = countBits(i);
            ans <<= k;
            ans += i;
            ans = ans % 1000000007;
        }
        return (int)ans;
    }
    
    int countBits(int n) {
        int count = 0;
        while(n) {
            n >>= 1;
            count++;
        }
        return count;
    }
};