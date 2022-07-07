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
        unordered_map<int, Employee*>m;
        for(auto x: employees) m[x->id] = x;
        int sum = 0;
        DFS(m, id, sum);
        return sum;
    }
    
    void DFS(unordered_map<int, Employee*>& m, int id, int& sum){
        sum += m[id]->importance;
        for(auto x: m[id]->subordinates) DFS(m, x, sum);
    }
    
    /*
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
    */
};