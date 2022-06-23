class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp = x;
        long long rev = 0;
        while(temp) {
            rev = rev*10 + temp%10;
            temp /= 10;
        }
        return rev == x;
    }
};