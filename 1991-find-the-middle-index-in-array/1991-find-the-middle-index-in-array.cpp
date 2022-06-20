class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int findMiddleIndex(vector<int>& A) {
        int left = 0, sum = 0;
        for(int i=0;i<A.size();i++) {
            sum += A[i];
        }
        for(int i=0;i<A.size();i++) {
            sum -= A[i];
            if(sum == left) return i;
            left += A[i];
        }
        return -1;
    }
};