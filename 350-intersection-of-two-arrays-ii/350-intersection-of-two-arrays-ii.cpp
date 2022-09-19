class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq1(1001), freq2(1001);
        for(int &x: nums1) {
            freq1[x]++;
        }
        for(int &x: nums2) {
            freq2[x]++;
        }
        vector<int> ans;
        for(int i = 0; i < 1001; ++i) {
            int cnt = min(freq1[i], freq2[i]);
            for(int j = 0; j < cnt; ++j) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};