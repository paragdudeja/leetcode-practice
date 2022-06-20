class Solution {
public:
    // Greedy
    // TC : O(N)
    // SC : O(1)
    
    int jump(vector<int>& nums) {
        int jumps = 0, currentReach = 0, maxReach = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);
            if(i == currentReach) {
                jumps++;
                currentReach = maxReach;
            }
        }
        return jumps;
    }
};