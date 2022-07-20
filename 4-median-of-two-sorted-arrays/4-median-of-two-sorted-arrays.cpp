class Solution {
public:
    // TC : O(M + N)
    // SC : O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        
        int mid1 = 0, mid2 = 0;
        int count = 0;
        
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                if(count == total/2) mid2 = nums1[i];
                if(count == total/2 - 1) mid1 = nums1[i];
                ++i;
            }
            else {
                if(count == total/2) mid2 = nums2[j];
                if(count == total/2 - 1) mid1 = nums2[j];
                ++j;
            }
            ++count;
        }
        
        while(i < m) {
            if(count == total/2) mid2 = nums1[i];
            if(count == total/2 - 1) mid1 = nums1[i];
            ++i;
            ++count;
        }
        while(j < n) {
            if(count == total/2) mid2 = nums2[j];
            if(count == total/2 - 1) mid1 = nums2[j];
            ++j;
            ++count;
        }
    
        
        return total & 1 ? mid2 : (mid1 + mid2)/2.0;
    }
    /* 
    // TC : O(M + N)
    // SC : O(M + N)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> v(m + n);
        int  i = 0, j = 0, k = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j])
                v[k++] = nums1[i++];
            else
                v[k++] = nums2[j++];
        }
        while(i < m) v[k++] = nums1[i++];
        while(j < n) v[k++] = nums2[j++];
        if((m + n)&1) return v[(m+n)/2];
        return (v[(m+n)/2] + v[(m+n)/2 - 1])/2.0;
    }
    */
};