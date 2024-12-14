/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0, i, n = secret.length();
        int countS[10] = {0};
        int countG[10] = {0};
        for (i = 0; i < n; i++) {
            if (secret[i] == guess[i])
                bull++;
            else {
                countS[secret[i] - '0']++;
                countG[guess[i] - '0']++;
            }
        }
        for (i = 0; i < 10; i++) {
            cow += min(countS[i], countG[i]);
        }
        return (to_string(bull) + "A" + to_string(cow) + "B");
    }
};
