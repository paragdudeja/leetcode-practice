class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(const int &num: nums) {
            freq[num]++;
        }
        
        int count = 0;
        
        if(k == 0) { // Pair with same value, different index
            for(auto it: freq) {
                if(it.second > 1) {
                    count++;
                }
            }
        }
        else { // Pair with value + k
            for(auto it: freq) {
                if(freq.find(it.first + k) != freq.end()) {
                    count++;
                }
            }
        }
        return count;
    }
};