class Solution {
public:
    // TC : O(N)
    // SC : O(N) 
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> hashset(nums.begin(), nums.end());
        
        for(const int &num: nums) {
            if(hashset.find(num-1) == hashset.end()) {
                int start = num;
                int end = start + 1;
                while(hashset.find(end) != hashset.end()) {
                    end++;
                }
                longest = max(longest, end - start);
            }
        }
        
        return longest;
    }
    
    /*
    // TC : O(N Log N)
    // SC : O(1)
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        sort(nums.begin(), nums.end());
        int longest = 1;
        int prev = nums[0];
        int current = 1;
        
        for(int i = 1; i < n; i++) {
            if(nums[i] == prev + 1) {
                current++;
            }
            else if(nums[i] != prev) {
                current = 1;
            }
            prev = nums[i];
            longest = max(longest, current);
        }
        
        return longest;
    }
    */
};