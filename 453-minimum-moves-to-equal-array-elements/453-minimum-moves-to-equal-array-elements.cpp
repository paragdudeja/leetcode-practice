class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MAX;
        for(const int &num: nums) {
            if(num < mn) mn = num;
        }
        int moves = 0;
        for(const int &num: nums)
            moves += num - mn;
        return moves;
    }
};