/*
Bruteforce Approach:
Time Complexity: O(n log n)
Space Complexity: O(1)
*/
    
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[(int)nums.size() / 2];
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freqmap;
        for (int num : nums) {
            freqmap[num]++;
            if (freqmap[num] > nums.size() / 2)
                return num;
        }
        assert(false);
        return INT_MAX;
    }
};
