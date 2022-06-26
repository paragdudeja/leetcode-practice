class Solution {
public:
    int countHousePlacements(int n) {
        int fib[n+1];
        fib[0] = 1, fib[1] = 2;
        for(int i = 2; i <= n; i++)
            fib[i] = (fib[i-1] + fib[i-2])%1000000007;
        
        return ((long long)fib[n] * fib[n])%1000000007;
    }
};