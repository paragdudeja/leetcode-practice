class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = nums[n/2];
        int moves = 0;
        for(auto &num: nums) {
            moves += abs(num - mid);
        }
        return moves;
    }
};