class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        int b = sqrt(c);
        
        while(a <= b) {
            long sum = (long)a*a + (long)b*b;
            if(sum == c) return true;
            else if(sum < c) ++a;
            else --b;
        }
        return false;
    }
};