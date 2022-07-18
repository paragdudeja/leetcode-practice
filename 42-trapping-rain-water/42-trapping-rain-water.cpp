class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1, leftMax = 0, rightMax = 0;
        int total = 0;
        
        while(left <= right) {
            if(height[left] <= height[right]) {
                if(height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {
                    total += leftMax - height[left];
                }
                left++;
            }
            else {
                if(height[right] >= rightMax) {
                    rightMax = height[right];
                }
                else {
                    total += rightMax - height[right];
                }
                right--;
            }
        }
        return total;
    }
    /*
    // TC : O(N)
    // SC : O(N) 
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Right Max
        int rightMax[n];
        rightMax[n-1] = height[n-1];
        
        for(int i = n - 2; i >= 0; i--) 
            rightMax[i] = max(rightMax[i + 1], height[i]); 
        
        int leftMax = 0;
        int totalWater = 0;
        
        for(int i = 0; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            totalWater += min(leftMax, rightMax[i]) - height[i];
        }
        
        return totalWater;
    }
    */
};