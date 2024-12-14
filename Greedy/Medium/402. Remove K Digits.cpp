/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == k)
            return "0";
        string ans;
        int i = 0;
        while (i < n && k > 0 && k < n - i) {
            if (num[i] <= num[i + 1]) {
                if (num[i] > '0' || !ans.empty()) {
                    ans.push_back(num[i]);
                }
            } 
            else {
                k--;
            }
            i++;
        }
        if (k == 0) {
            if (ans.empty()) {
                while (i < n && num[i] == '0')
                    i++;
            }
            ans.insert(ans.end(), num.begin() + i, num.end());
        }
        if (ans.empty())
            ans = "0";
        return ans;
    }
};
