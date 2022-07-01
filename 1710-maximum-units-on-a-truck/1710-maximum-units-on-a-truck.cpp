class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const auto &v1, const auto &v2){
            return v1[1] > v2[1];
        });
        
        int boxes = 0;
        for(const auto &v: boxTypes) {
            if(v[0] >= truckSize) {
                boxes += truckSize * v[1];
                break;
            }
            else {
                boxes += v[0] * v[1];
                truckSize -= v[0];
            }
        }
        return boxes;
    }
};