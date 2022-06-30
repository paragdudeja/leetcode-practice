class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // if(n&1) {
            int mid = nums[n/2];
            int moves = 0;
            for(auto &num: nums) {
                moves += abs(num - mid);
            }
            return moves;
        // }
        /*
        else {
            int mid1 = nums[n/2 - 1];
            int mid2 = nums[n/2];
            int moves1 = 0, moves2 = 0;
            for(auto &num: nums) {
                moves1 += abs(num - mid1);
                moves2 += abs(num - mid2);
            }
            return min(moves1,  moves2);
        }
        */
    }
};