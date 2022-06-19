class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp1, mp2;
        
        for(int &n1: nums1) {
            for(int &n2: nums2) {
                mp1[n1 + n2]++;
            }
        }
        
        for(int &n3: nums3) {
            for(int &n4: nums4) {
                mp2[n3 + n4]++;
            }
        }
        
        int ans = 0;
        for(auto it: mp1) {
            if(mp2.find(-it.first) != mp2.end()) {
                ans += mp1[it.first] * mp2[-it.first];
            }
        }
        return ans;
    }
};