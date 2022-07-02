class Solution {
public:
    
    int merge(vector<int> &nums, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        int left[n1], right[n2];
        
        for(int i = 0; i < n1; i++) {
            left[i] = nums[i + low];
        }
        
        for(int i = 0; i < n2; i++) {
            right[i] = nums[i + mid + 1];
        }
        
        int count = 0, i = 0, j = 0, k = low;
        for(i = 0; i < n1; i++) {
            while(j < n2 && left[i] > 2LL * right[j]) {
                j++;
            }
            count += j;
        }
        
        i = 0, j = 0, k = low;
        while(i < n1 && j < n2) {
            if(left[i] <= right[j]) {
                nums[k++] = left[i++];
            }
            else {
                nums[k++] = right[j++];
            }
        }
        
        while(i < n1) nums[k++] = left[i++];
        while(j < n2) nums[k++] = right[j++];
        return count;
    }
    
    int mergeSort(vector<int> &nums, int low, int high) {
        
        if(low >= high) return 0; 
        int count = 0;
        
        int mid = low + (high - low)/2;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);
        
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
    /*
    // Brute
    // TC : O(N^2)
    // SC : O(1)
    int reversePairs(vector<int>& nums) {
        int count = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(1LL * nums[i] > 2LL * nums[j]) count++;
            }
        }
        return count;
    }
    */
};