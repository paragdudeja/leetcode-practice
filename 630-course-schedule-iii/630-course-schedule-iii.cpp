class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto &course1, const auto &course2){
            return course1[1] < course2[1];
        });    
        
        priority_queue<int> pq; // max heap
        int days = 0;
        for(const auto &course: courses) {
            if(days + course[0] <= course[1]) {
                days += course[0];
                pq.push(course[0]);
            }
            else if(!pq.empty() && pq.top() > course[0]) {
                days -= pq.top();
                pq.pop();
                
                pq.push(course[0]);
                days += course[0];
            }
            else {
                // reject
            }
        }
        return pq.size();
    }
};