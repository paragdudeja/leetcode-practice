class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int votes = 0;
        int candidate = INT_MIN;
        for(const int &num: nums) {
            if(num == candidate) 
                votes++;
            else if(votes == 0) {
                // votes = 1;
                candidate = num;
            }
            else {
                votes--;
            }
        }
        return candidate;
    }
};