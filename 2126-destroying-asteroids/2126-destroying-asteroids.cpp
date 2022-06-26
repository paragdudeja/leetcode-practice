class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for(const int &wt: asteroids) {
            if(m >= wt)
                m += wt;
            else
                return false;
        }
        return true;
    }
};