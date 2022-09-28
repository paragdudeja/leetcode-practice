class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<long long> force(n);
        
        long long current_force = 0;
        
        for(int i = 0; i < n; ++i) {
            if(dominoes[i] == 'R') {
                current_force = n;
            }
            else if(dominoes[i] == 'L') {
                current_force = 0;
            }
            else {
                current_force = max(current_force-1, 0LL);
            }
            force[i] += current_force;
        }
        
        current_force = 0;
        for(int i = n-1; i >= 0; --i) {
            if(dominoes[i] == 'L') {
                current_force = n;
            }
            else if(dominoes[i] == 'R') {
                current_force = 0;
            }
            else {
                current_force = max(current_force-1, 0LL);
            }
            force[i] -= current_force;
        }
        
        string result;
        for(long long f: force) {
            if(f == 0) {
                result.push_back('.');
            }
            else if(f > 0) {
                result.push_back('R');
            }
            else {
                result.push_back('L');
            }
        }
        
        return result;
    }
};