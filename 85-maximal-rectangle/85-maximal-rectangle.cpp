class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        vector<int> current(n);
        int maxRectangle = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '0') {
                    current[j] = 0;
                }
                else {
                    current[j] += 1;
                }
            }
            maxRectangle = max(maxRectangle, largestRectangleHistogram(current));
        }
        return maxRectangle;
    }
    
    int largestRectangleHistogram(vector<int> &nums) {
        vector<int> left = getPrevSmaller(nums);
        vector<int> right = getNextSmaller(nums);
        
        int maxArea = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            maxArea = max(maxArea, nums[i] * (right[i] - left[i] - 1));
        }
        return maxArea;
    }
    
    vector<int> getPrevSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> prev(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }
    
    vector<int> getNextSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> next(n);
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return next;
    }
};