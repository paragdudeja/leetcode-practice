class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        unordered_map<int, int> m;
        for(int num: nums)
            m[num]++;
        dfs(m, nums, curr, res);
        return res;
    }
    
    void dfs(unordered_map<int, int> &m, vector<int> &nums, vector<int> &curr, vector<vector<int>> &res) {
        if(curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        
        for(auto &it: m) {
            if(it.second > 0) {
                m[it.first]--;
                curr.push_back(it.first);
                dfs(m, nums, curr, res);
                m[it.first]++;
                curr.pop_back();
            } 
        }
    }
};