class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        long long pow[n+1];
        pow[0] = 1;
        
        for(int i = 1; i <= n; ++i) {
            pow[i] = (pow[i-1]*2) % 1000000007;
        }
        
        long long sum = 0;
        for(int i = 0; i < n; ++i) {
            long long min_count = pow[n - i - 1];
            long long max_count = pow[i];
            sum += (-min_count * nums[i]) + (max_count * nums[i]);
            sum = sum % 1000000007;
        }
        return sum;
    }
}; 