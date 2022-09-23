class Solution {
public:
    int concatenatedBinary(int n) {
        long res = 1, mod = 1e9+7, len_of_curr = 1;
        for (int i = 2; i <= n; i++) {
		
			// the len increases every time we reach a number which is a power of two.
            if ((i & (i-1)) == 0)
                len_of_curr++;
				
            res = (res << len_of_curr) % mod;
            res += i % mod;
        }
        return res;
    }
    
    /*
    int countBits(int n) {
        int count = 0;
        while(n) {
            n >>= 1;
            count++;
        }
        return count;
    }
    */
};