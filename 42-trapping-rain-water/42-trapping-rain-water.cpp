class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        
        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]); 
        }
        
        int leftMax = 0;
        int totalWater = 0;
        
        for(int i = 0; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            int water = min(leftMax, rightMax[i]) - height[i];
            totalWater += water;
        }
        
        return totalWater;
    }
};