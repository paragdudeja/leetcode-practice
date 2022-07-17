class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector <pair <string,int> > v[110];
        for (int i=1; i<=nums[0].size(); i++){
            for (int j=0; j<nums.size(); j++){
                v[i].push_back({nums[j].substr(nums[0].size()-i,i),j});
            }
            sort(v[i].begin(),v[i].end());
        }
        vector <int> ans;
        for (auto i:queries){
            ans.push_back(v[i[1]][i[0]-1].second);
        }
        return ans;
    }
};