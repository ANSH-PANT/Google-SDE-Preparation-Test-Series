/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, n = colors.size();
        int result = 0;
        while (i < n) {
            int sum = neededTime[i], maxval = neededTime[i];
            i++;
            while (i < n && colors[i - 1] == colors[i]) {
                sum += neededTime[i];
                maxval = max(maxval, neededTime[i]);
                i++;
            }
            result += sum - maxval;
        }
        return result;
    }
};
