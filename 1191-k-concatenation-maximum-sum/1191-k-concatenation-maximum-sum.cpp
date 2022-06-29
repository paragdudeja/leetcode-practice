class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const long long  MOD = 1e9 + 7;
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(k == 1) {
            return kadanes(arr)%MOD;
        }
        else if(sum < 0) {
            return kadanesOfTwo(arr)%MOD;
        }
        else {
            return (kadanesOfTwo(arr) + (long long)sum * (k-2))%MOD;
        }
    }
    
    int kadanes(vector<int> &nums) {
        int currSum = 0, maxSum = 0;
        for(const int &num: nums) {
            currSum = currSum + num;
            if(currSum > maxSum) {
                maxSum = currSum;
            }
            if(currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
    
    int kadanesOfTwo(vector<int> &nums) {
        vector<int> doubled;
        int n = nums.size();
        for(int i = 0; i < n*2; i++)
            doubled.push_back(nums[i%n]);
        
        return kadanes(doubled);
    }
};