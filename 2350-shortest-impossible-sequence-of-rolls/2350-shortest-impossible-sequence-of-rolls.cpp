class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        vector<priority_queue<int, vector<int>, greater<int>>> v(k+1);
        
        for(int i = 0; i < rolls.size(); ++i)
            v[rolls[i]].push(i);
        
        int mx = -1;
        int ans = 1;
        while(true) {
            int curr = mx;
            for(int i = 1; i <= k; ++i) {
                while(!v[i].empty() && v[i].top() < mx) {
                    v[i].pop();
                }
                if(v[i].empty()) {
                    return ans;
                    // else return 0;
                }
                // cout << v[i].top() << endl;
                curr = max(curr, v[i].top());
                v[i].pop();
            }
            // cout << endl;
            ++ans;
            mx = curr;
        }
        return 0;
    }
};