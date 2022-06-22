class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mp(10001);
        
        stack<int> st;
        int n = nums2.size();
        vector<int> nextGreater(n);
        
        // Next Greater
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i])
                st.pop();
            nextGreater[i] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
            mp[nums2[i]] = i;
        }
        
        for(int &num: nums1) {
            num = nextGreater[mp[num]];
        }
        
        return nums1;
    }
};