class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        if(num%10 == k) return 1;
        if(k == 0) return -1;
        int count = 1;
        while(num >= k) {
            count++;
            num -= k;
            if(num%10 == k)
                return count;
        }
        return -1;
    }
};