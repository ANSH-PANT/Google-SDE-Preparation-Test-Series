/*
Bruteforce Approach:
Time Complexity: O(32)
Space Complexity: O(1)
*/

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n > 0) {
            if(n & 1) count++;
            n >>= 1;
        }
        return count;
    }
};

/*
Better Approach:
Time Complexity: O(k)
Space Complexity: O(1)
*/

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n > 0) {
            n &= (n-1);
            count++;
        }
        return count;
    }
};

/*
Optimised Approach:
Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
