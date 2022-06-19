class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int maxScore(vector<int>& cardPoints, int k) {
        int n = (int)cardPoints.size(), total = 0;
        for(int i = 0; i < n; i++) {
            total += cardPoints[i];
        }
        
        int windowSize = n - k;
        if(windowSize == 0) {
            return total;
        }
        
        int windowSum = 0;
        for(int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }
        
        int minWindowSum = windowSum;
        for(int i = windowSize; i < n; i++) {
            windowSum = windowSum + cardPoints[i] - cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }
        return total - minWindowSum;
    }
};