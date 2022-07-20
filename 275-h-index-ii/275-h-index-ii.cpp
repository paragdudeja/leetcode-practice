class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        
        int n = citations.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high -low)/2;
            int h = n - mid;
            if(citations[mid] >= h) {
                ans = h;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};