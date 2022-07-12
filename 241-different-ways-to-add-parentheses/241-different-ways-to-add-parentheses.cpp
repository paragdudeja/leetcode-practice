class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        return solve(0, n-1, expression);
    }
    
    vector<int> solve(int start, int end, string &expression) {
        if(end - start < 2) {
            int num = 0;
            for(int i = start; i <= end; i++) {
                num = num * 10 + (expression[i] - '0');
            }
            return {num};
        }
        
        
        vector<int> res;
        for(int i = start+1; i < end; i++) {
            if(expression[i] == '+') {
                vector<int> left = solve(start, i-1, expression);
                vector<int> right = solve(i+1, end, expression);
                // vector<int> res;
                for(const int &l: left) {
                    for(const int &r: right) {
                        res.push_back(l+r);
                    }
                }
            }
            else if(expression[i] == '-') {
                vector<int> left = solve(start, i-1, expression);
                vector<int> right = solve(i+1, end, expression);
                // vector<int> res;
                for(const int &l: left) {
                    for(const int &r: right) {
                        res.push_back(l-r);
                    }
                }
            }
            else if(expression[i] == '*') {
                vector<int> left = solve(start, i-1, expression);
                vector<int> right = solve(i+1, end, expression);
                // vector<int> res;
                for(const int &l: left) {
                    for(const int &r: right) {
                        res.push_back(l*r);
                    }
                }
            }
        }
        return res;
    }
};