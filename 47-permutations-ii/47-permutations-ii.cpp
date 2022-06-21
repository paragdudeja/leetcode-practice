class Solution {
public:
    void perm(int index, vector<vector<int>> &ans, vector<int> &nums){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        
        unordered_set<int> s;
        for(int i = index; i < nums.size(); i++) {
            if(s.count(nums[i])) continue;
            s.insert(nums[i]);
            swap(nums[i], nums[index]);
            perm(index+1, ans, nums);
            swap(nums[i], nums[index]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        // sort(nums.begin(), nums.end());
        perm(0, ans, nums);
        return ans;
    }
};