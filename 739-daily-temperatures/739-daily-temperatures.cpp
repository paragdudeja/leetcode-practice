class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> nextGreater(n);
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
            if(st.size())
                nextGreater[i] = st.top() - i;
            st.push(i);
        }
        return nextGreater;
    }
};