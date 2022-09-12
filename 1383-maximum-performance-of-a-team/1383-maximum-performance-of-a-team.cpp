struct Engineer {
    int speed;
    int efficiency;
};

struct CompareEngineer {
    bool operator()(Engineer const& e1, Engineer const& e2) {
        return e1.speed > e2.speed;
    }
};

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Engineer> engineers;
        for(int i = 0; i < n; i++) {
            engineers.push_back({speed[i], efficiency[i]});
        }
        
        sort(engineers.begin(), engineers.end(), [](Engineer &e1, Engineer &e2){
            return e1.efficiency > e2.efficiency; 
        });
        
        priority_queue<Engineer, vector<Engineer>, CompareEngineer> pq;
        
        long long teamSpeed = 0;
        long long maxPerformance = 0;
        
        for(Engineer &engineer: engineers) {
            if(pq.size() == k) {
                teamSpeed -= pq.top().speed;
                pq.pop();
            }
            pq.push(engineer);
            teamSpeed += engineer.speed;
            long long performance = teamSpeed * engineer.efficiency;
            maxPerformance = max(maxPerformance, performance);
        }
        
        return (maxPerformance%1000000007);
    }
};