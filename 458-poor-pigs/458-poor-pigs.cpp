class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        double a = log(buckets);
        double b = log(minutesToTest/minutesToDie + 1);
        return ceil(a/b);
    }
};