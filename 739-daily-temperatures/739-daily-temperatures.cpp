class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> nextGreater(n);
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
            nextGreater[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return nextGreater;
    }
};