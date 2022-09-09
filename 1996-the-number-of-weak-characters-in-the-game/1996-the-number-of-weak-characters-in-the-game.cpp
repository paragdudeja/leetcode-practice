class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](vector<int> &v1, vector<int> &v2){
            if(v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0] < v2[0];
        });
        
        int mx = 0, count = 0;
        for(int i = properties.size()-1; i >= 0; --i) {
            if(properties[i][1] < mx) {
                ++count;
            }
            mx = max(mx, properties[i][1]);
        }
        return count;
    }
};