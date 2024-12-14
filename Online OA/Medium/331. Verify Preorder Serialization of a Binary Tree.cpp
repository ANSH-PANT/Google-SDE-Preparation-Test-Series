/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> stk;
        bool isNum = false;
        preorder.push_back(',');
        for (auto c : preorder) {
            if (c == '#') {
                while (!stk.empty() && stk.top() == '#') {
                    stk.pop();
                    if (stk.empty() || stk.top() == '#')
                        return false;
                    stk.pop();
                }
                stk.push('#');
            } 
            else if (c == ',') {
                if (isNum)
                    stk.push('n');
                isNum = false;
            } 
            else {
                isNum = true;
            }
        }
        return stk.size() == 1 && stk.top() == '#';
    }
};
