class Solution {
public:
    int getCountToTarget(vector<int> &nums, int target) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        
        for(const int &num: nums) {
            sum += num;
            count += mp.find(sum - target) == mp.end() ? 0 : mp[sum - target];
            mp[sum]++;
        }
        return count;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        
        for(int startRow = 0; startRow < m; ++startRow) {
            vector<int> nums(n);
            for(int currentRow = startRow; currentRow < m; ++currentRow) {
                for(int col = 0; col < n; ++col) {
                    nums[col] += matrix[currentRow][col];
                }
                count += getCountToTarget(nums, target);
            }
        }
        return count;
    }
    /*
    Based on 2-D Range queries
    // TC : O(M^2 * N^2)
    // SC : O(M * N)
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int row = 0; row <= i; row++) {
                for(int j = 0; j < n; j++) {
                    for(int col = 0; col <= j; col++) {
                        int sum = dp[i+1][j+1] - dp[i+1][col] - dp[row][j+1] + dp[row][col];
                        if(sum == target) ++count;
                    }
                }
            }
        }
        return count;
    }
    */
};