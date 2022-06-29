class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto &v1, auto &v2){
            if(v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0] < v2[0];
        });
        
        
        int n = people.size();
        vector<int> slots(n, 1);
        vector<vector<int>> ans(n);

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(slots[j] == 1) {
                    if(cnt == people[i][1]) {
                        slots[j] = 0;
                        ans[j] = people[i];
                        break;
                    }
                    cnt++;
                }
            }
        }
        return ans;
    }
};