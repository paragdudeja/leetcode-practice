class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0, oddSum = 0;
        for(int &num: nums) {
            if(num&1) oddSum += num;
            else evenSum += num;
        }
        
        vector<int> ans;
        for(auto & q: queries) {
            int val = q[0], idx = q[1];
            int prev_num = nums[idx];
            int new_num = prev_num + val;
            nums[idx] = new_num;
            
            if(prev_num & 1) oddSum -= prev_num;
            else evenSum -= prev_num;
              
            if(new_num & 1) oddSum += new_num;
            else evenSum += new_num;
            
            ans.push_back(evenSum);
        }
        
        return ans;
    }
};