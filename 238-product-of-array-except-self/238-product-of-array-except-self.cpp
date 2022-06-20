class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prods(n, 1);
        // Left products
        for (int i = 1; i < n; i++) {
            prods[i] = prods[i - 1] * nums[i - 1];
        }
        
        // Rigth products
        for (int j = n - 1, right = 1; j >= 0; j--) {
            prods[j] *= right;
            right *= nums[j];
        }
        return prods;
    }
};