class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const auto &point1, const auto &point2){
            return pow(point1[0], 2) + pow(point1[1], 2) < pow(point2[0], 2) + pow(point2[1], 2);
        });
        
        points.resize(k);
        return points;
    }
};