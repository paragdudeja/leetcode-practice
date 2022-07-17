class Solution {
public:
    // Using monototonic stack
    // TC : O(N) One pass
    // SC : O(N)
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> st;
        int n = heights.size();
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = 0;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                maxArea = max(maxArea, height * width);                
            }
            st.push(i);
        }
        return maxArea;
    }
    /*
    // Using monototonic stack
    // TC : O(N)
    // SC : O(N)
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevSmaller = getPrevSmaller(heights);
        vector<int> nextSmaller = getNextSmaller(heights);
        
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1));
        }
        return maxArea;
    }
    
    vector<int> getPrevSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> prevSmaller(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prevSmaller;
    }
    
    vector<int> getNextSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> nextSmaller(n);
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nextSmaller;
    }
    */
};