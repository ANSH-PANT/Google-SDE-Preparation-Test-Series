/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int count = 0;
        int max_frequency = 0;
        int expand_str = 0;
        int shrink_str = 0;
        int max_length = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        while (expand_str < n) {
            mp[s[expand_str]]++;
            max_length = expand_str - shrink_str + 1;
            for (auto i : mp) {
                if (i.second > max_frequency) {
                    max_frequency = i.second;
                }
            }
            if (max_length - max_frequency <= k) {
                count = max(max_length, count);
                expand_str++;
            } else {
                mp[s[shrink_str]]--;

                expand_str++;
                shrink_str++;
            }
        }
        return count;
    }
};
