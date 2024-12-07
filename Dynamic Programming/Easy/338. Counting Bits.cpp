/*
Bruteforce Approach:
Time complexity: O(n * log n)
Space complexity: O(n)
*/

class Solution {
private:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }

public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i] = hammingWeight(i);
        }
        return ans;
    }
};

/*
Optimised Approach:
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<int> countBits(int n) {
        n++;
        vector<int> tempArray(n, 0);
        int targetPower = 1;
        int counter = 0;
        for (int i = 1; i < n; i++) {
            if (counter == targetPower) {
                counter = 0;
                targetPower *= 2;
            }
            tempArray[i] = tempArray[counter] + 1;
            counter++;
        }
        return tempArray;
    }
}
