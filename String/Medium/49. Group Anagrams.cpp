/*
Time Complexity: O(n⋅mlogm), where n is the number of strings and m is the maximum length of a string.
Space Complexity: O(n⋅m)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            string tmp = s;
            sort(s.begin(), s.end());
            mp[s].push_back(tmp);
        }
        for (auto it : mp)
            res.push_back(it.second);
        return res;
    }
};
