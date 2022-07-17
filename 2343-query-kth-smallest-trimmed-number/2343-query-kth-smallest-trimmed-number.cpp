class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums[0].size();
        
        for(const auto &q: queries) {
            int trim = q[1];
            int k = q[0];
            int start = n-trim;
            
            vector<pair<string, int>> v;
            int i = 0;
            for(const auto &num: nums) {
                string curr = num.substr(start);
                v.push_back({curr, i++});
            }
            sort(v.begin(), v.end(), [](const auto &v1, const auto &v2){
                // if(v1.first == v2.first) return v1.second < v2.second;
                for(int i = 0; i < v1.first.size(); i++) {
                    if(v1.first[i] < v2.first[i]) return true;
                    else if(v1.first[i] > v2.first[i]) return false;
                }
                return v1.second < v2.second;
            });
            res.push_back(v[k-1].second);
        }
        // cout << endl;
        return res;
    }
};