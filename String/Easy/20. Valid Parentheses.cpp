/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        string pending;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                pending.push_back(c);
            else {
                if (c == ')') {
                    if (pending.empty() || pending.back() != '(')
                        return false;
                    else
                        pending.pop_back();
                } else if (c == ']') {
                    if (pending.empty() || pending.back() != '[')
                        return false;
                    else
                        pending.pop_back();
                }
                if (c == '}') {
                    if (pending.empty() || pending.back() != '{')
                        return false;
                    else
                        pending.pop_back();
                }
            }
        }
        return pending.empty();
    }
};
