class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        for(int i = 1; i < 10; ++i) {
            q.push(i);
        }
        
        for(int i = 1; i < n; ++i) {
            int s = q.size();
            while(s--) {
                int num = q.front();
                q.pop();
                
                int last_digit = num%10;
                if(last_digit + k < 10) {
                    q.push(num*10 + last_digit + k);
                }
                if(last_digit - k >= 0 && k!= 0) {
                    q.push(num*10 + last_digit - k);
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};