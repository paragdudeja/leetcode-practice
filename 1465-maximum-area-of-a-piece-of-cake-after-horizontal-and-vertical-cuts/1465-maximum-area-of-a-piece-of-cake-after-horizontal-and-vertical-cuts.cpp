class Solution {
public:
    // TC: O(N log N)
    // SC : O(1)
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int mx_len = max(horizontalCuts[0], h - horizontalCuts.back());
        int mx_width = max(verticalCuts[0], w - verticalCuts.back());
        
        for(int i = 1; i < horizontalCuts.size(); i++) {
            mx_len = max(mx_len, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        for(int i = 1; i < verticalCuts.size(); i++) {
            mx_width = max(mx_width, verticalCuts[i] - verticalCuts[i-1]);
        }
        
        return ((long long)mx_len * mx_width)%1000000007;
    }
};