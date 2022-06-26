class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dups;
        
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0) dups.push_back(abs(nums[i]));
            nums[index] = -nums[index];
        }
        return dups;
        
    }
    
    /*
    // Hast set, duplicate if present in set
    // TC : O(N)
    // SC : O(N)
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        
        vector<int> dups;
        for(const int &num: nums) {
            if(s.find(num) != s.end()) {
                dups.push_back(num);
            }
            else {
                s.insert(num);
            }
        }
        return dups;
    }
    */
    
    /*
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
    */
    
    // Brute: Two loops, nested
    // TC : O(N^2)
    // SC : O(1)
};