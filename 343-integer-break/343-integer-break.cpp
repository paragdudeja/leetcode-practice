class Solution {
public:
    int integerBreak(int n) {
        int val[n+1];
        val[0] = val[1] = 0;

       for (int i = 1; i <= n; i++)
       {
          int max_val = 0;
          for (int j = 1; j <= i; j++)
             max_val = max({max_val, (i-j)*j, j*val[i-j]});
          val[i] = max_val;
       }
       return val[n];

    }
    /*
    int integerBreak(int n) {
        if(n <= 2) return 1;
        if(n == 3) return 2;
        int prod = 1;
        while(n > 4) {
            n -= 3;
            prod *= 3;
        }
        return prod * n;
    }
    */
};