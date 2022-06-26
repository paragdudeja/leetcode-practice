class Solution {
public:
    // Sort, check if consecutives are equal
    // TC : O(N Log N)
    // SC : O(1)
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> dups;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) {
                dups.push_back(nums[i]);
            }
        }
        return dups;
    }
    
    
    // Brute: Two loops, nested
    // TC : O(N^2)
    // SC : O(1);
};