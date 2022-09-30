struct Point {
    int x;
    int y;
    bool is_start;
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Point> points;
        for(auto &b: buildings) {
            points.push_back({b[0], b[2], true}); // start point
            points.push_back({b[1], b[2], false}); // end point
        }
        
        sort(points.begin(), points.end(), [](auto &p1, auto &p2){
            // if(p1.is_start && p2.is_start) {
            //     if(p1.x == p2.x) return p1.y > p2.y;
            //     return p1.x < p2.x;
            // }
            // else if(!p1.is_start && !p2.is_start) {
            //     if(p1.x == p2.x) return p1.y < p2.y;
            //     return p1.x < p2.x;
            // }
            // else {
            //     if(p1.x == p2.x) return p2.is_start;
            //     return p1.x < p2.x;
            // }
            if(p1.x != p2.x) {
                return p1.x < p2.x;
            }
            else {
                if(p1.is_start && p2.is_start) return p1.y > p2.y;
                else if(!p1.is_start && !p2.is_start) return p1.y < p2.y;
                else return p1.is_start;
            }
        });
        
        map<int, int> mp;
        mp[0] = 1;
        
        int max_val = 0;
        vector<vector<int>> skyline;
        
        for(auto &point: points) {
            if(point.is_start) { // start point
                mp[point.y]++;
                if(mp[point.y] == 1 && point.y > max_val) {
                    max_val = point.y;
                    skyline.push_back({point.x, point.y});
                }
            }
            else { //  end point
                mp[point.y]--;
                if(mp[point.y] == 0) mp.erase(point.y);
                if(mp.rbegin()->first < max_val) {
                    max_val = mp.rbegin()->first;
                    skyline.push_back({point.x, max_val});
                }
            }
        }
        
        return skyline;
    }
};