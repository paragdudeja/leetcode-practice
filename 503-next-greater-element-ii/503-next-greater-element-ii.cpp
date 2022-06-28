class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            st.push(nums[i]);
        }
        
        vector<int> nextGreater(n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            nextGreater[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        
        return nextGreater;
    }
};