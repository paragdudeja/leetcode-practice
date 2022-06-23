class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token: tokens) {
            if(isOperator(token)) {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                st.push(performOperation(token[0], operand1, operand2));
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
    
    bool isOperator(string token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    
    int performOperation(char current_operator, int operand1, int operand2) {
        int result = 0;
        
        if(current_operator == '+')
            result = operand1 + operand2;
        else if(current_operator == '-')
            result = operand1 - operand2;
        else if(current_operator == '*')
            result = operand1 * operand2;
        else
            result = operand1 / operand2;
        
        return result;
        
    }
};