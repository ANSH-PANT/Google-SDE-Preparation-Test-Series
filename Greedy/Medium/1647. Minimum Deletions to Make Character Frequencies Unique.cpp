/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int, int> hm;
        vector<int> vec(26, 0);
        for (char c : s) {
            vec[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            hm[vec[i]]++;
        }
        hm[0] = 0;
        int count = 0;
        for (int i = 0; i < 26; i++) {
            int f = vec[i];
            if (hm[f] > 1) {
                for (int j = f - 1; j >= 0; j--) {
                    if (j == 0) {
                        count += f;
                    } 
                    else if (hm.count(j) == 0) {
                        hm[j] = 1;
                        count += f - j;
                        break;
                    }
                }
                hm[f]--;
            }
        }
        return count;
    }
};
