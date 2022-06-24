class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftBound = prevSmaller(arr, n);
        vector<int> rightBound = nextSmaller(arr, n);
               
        long long sum = 0;
        
        for(int i = 0; i < n; i++) {
            int leftCount = i - leftBound[i];
            int rightCount = rightBound[i] - i;
            sum += (long long)arr[i] * leftCount * rightCount;
            sum %= 1000000007;
        }
        return sum;
    }
    
    vector<int> prevSmaller(vector<int> &arr, int n) {
        vector<int> prev(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        return prev;
    }
    
    vector<int> nextSmaller(vector<int> &arr, int n) {
        vector<int> next(n);
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        return next;
    }
};