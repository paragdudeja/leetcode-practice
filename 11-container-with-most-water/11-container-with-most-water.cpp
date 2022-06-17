class Solution {
public:
    
    // TC : O(N)
    // SC : O(1)
    int maxArea(vector<int>& height) {
        int maximumArea = 0;
        int left = 0, right = height.size() - 1;
        
        while(left < right) {
            int width = right - left;
            int length = min(height[left], height[right]);
            int area = length * width;
            if(area > maximumArea) {
                maximumArea = area;
            }
            
            // moving the larger would definitely not increase area
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maximumArea;
    }
};