class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        bool neg = false;
        if(nn < 0) {
            nn = -nn;
            neg = true;
        }
        
        while(nn > 0) {
            if(nn & 1) {
                ans = ans * x;
                nn--;
            }
            else {
                x = x*x;
                nn /= 2;
            }
        }
        return neg ? 1/ans: ans;
    }
};