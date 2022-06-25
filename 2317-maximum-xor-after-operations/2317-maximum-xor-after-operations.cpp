class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int current = 0;
        for(int &num: nums)
            current |= num;       
        
        return current;
    }
};