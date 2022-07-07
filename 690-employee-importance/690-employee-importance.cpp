/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> scores;
        
        for(auto &emp: employees) {
            scores[emp->id] = emp->importance;
            // for(auto &sub: emp->subordinates) {
            //     mp[emp->id].push_back(sub);
            // }
            mp[emp->id] = emp->subordinates;
        }
        
        int total = scores[id];
        queue<int> q;
        q.push(id);
        
        while(!q.empty()) {
            int empid = q.front();
            q.pop();
            
            for(auto &sub: mp[empid]) {
                q.push(sub);
                total += scores[sub];
            }
        }
        return total;
    }
};