class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int maxScore(vector<int>& cardPoints, int k) {
        int n = (int)cardPoints.size(), lSum = 0;
        for(int i = 0; i < k; ++i){
            lSum += cardPoints[i];
        }
        int maxPoints = lSum;
        for(int rSum = 0, i = 0; i < k; ++i){
            rSum += cardPoints[n-1-i];
            lSum -= cardPoints[k-1-i];
            maxPoints = max(maxPoints,lSum+rSum);
        }
        return maxPoints;
    }
};