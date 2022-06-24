class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<int> pq;
        for(const int &num: target) {
            sum += num;
            pq.push(num);
        }
        
        int n = target.size();
        
        while(!pq.empty()) {
            int mx = pq.top();
            pq.pop();
            
            long long remaining = sum - mx;
            
            
            if(mx == 1 || remaining == 1) break;
            
            if(remaining == 0 || mx < remaining) return false;
            
            int updatedMax = mx % remaining;
                
            if(updatedMax >= 1){
                pq.push(updatedMax);
                sum = updatedMax + remaining;
            }
            else return false;
        }
        return true;
    }
};