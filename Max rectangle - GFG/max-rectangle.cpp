// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> current(m);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(M[i][j] == 0)
                    current[j] = 0;
                else
                    current[j] += M[i][j];
            }
            ans = max(ans, maxHistogram(current));
        }
        return ans;
    }
    
    int maxHistogram(vector<int> &nums) {
        vector<int> left = prevSmaller(nums);
        vector<int> right = nextSmaller(nums);
        int n = nums.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, nums[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
    
    vector<int> prevSmaller(vector<int> &nums) {
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
    
    vector<int> nextSmaller(vector<int> &nums) {
        int n = nums.size();
        
        vector<int> next(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return next;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends