/*
Time Complexity: O(n) 
Space Complexity: O(n) 
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                if (tokens[i] == "+")
                    op1 = op2 + op1;
                if (tokens[i] == "-")
                    op1 = op2 - op1;
                if (tokens[i] == "*")
                    op1 = op2 * op1;
                if (tokens[i] == "/")
                    op1 = op2 / op1;
                s.push(op1);
            } 
            else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
