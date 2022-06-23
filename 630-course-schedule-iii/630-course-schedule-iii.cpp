class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto &course1, const auto &course2){
            return course1[1] < course2[1];
        });
        
        priority_queue<int> pq;
        int days = 0;
        for(auto &course : courses) {
            days += course[0];
            pq.push(course[0]);
            if(days > course[1]) {
                days -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};