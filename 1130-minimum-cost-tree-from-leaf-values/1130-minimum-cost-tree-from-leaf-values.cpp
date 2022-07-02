// struct Result {
//     int max_num;
//     int sum;
//     Result(int max_num, int sum) : max_num(max_num), sum(sum) { }
// };

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : arr) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
    
    /*
    // MCM
    // TC : O(N*N*N) i.e. O(N^3)
    // SC : O(N*N) i.e. O(N^2)
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, {-1,-1}));
        vector<int> solution = solve(0, n-1, arr, dp);
        return solution[1];
    }
    
    vector<int> solve(int left, int right, vector<int> &arr, vector<vector<vector<int>>> &dp) {
        if(dp[left][right][0] != -1) return dp[left][right];
        if(left > right) {
            return {1, 0};
        }
        if(left == right) {
            return {arr[left], 0};
        }
        vector<int> min_res{-1, -1};
        for(int i = left; i < right; i++) {
            vector<int> left_res = solve(left, i, arr, dp);
            vector<int> right_res = solve(i+1, right, arr, dp);
            vector<int> res = {max(left_res[0], right_res[0]), left_res[1] + right_res[1] 
                + left_res[0]*right_res[0]};
            if(min_res[0] == -1)
                min_res = res;
            else if(min_res[1] > res[1])
                min_res = res;
        }
        return dp[left][right] = min_res;
    }
    */
};