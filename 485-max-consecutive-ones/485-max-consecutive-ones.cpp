class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int longest = 0;
        int start = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                start = i;
            } 
            else {
                if(i - start > longest) {
                    longest = i - start;
                }
            }
        }
        return longest;
    }
};