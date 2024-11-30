/*
Time Complexity: O(Cn⋅2n), where 𝐶𝑛 is the n-th Catalan number.
Space Complexity: O(Cn⋅2n)
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> all;
        string perm;
        traverse(n, 0, 0, perm, all);
        return all;
    }

private:
    void traverse(const int n, int n1, int n2, string& perm,
                  vector<string>& all) {
        if (n1 == n && n2 == n)
            all.push_back(perm);
        else {
            if (n1 < n) {
                perm.push_back('(');
                traverse(n, n1 + 1, n2, perm, all);
                perm.pop_back();
            }
            if (n2 < n && n1 > n2) {
                perm.push_back(')');
                traverse(n, n1, n2 + 1, perm, all);
                perm.pop_back();
            }
        }
    }
};
