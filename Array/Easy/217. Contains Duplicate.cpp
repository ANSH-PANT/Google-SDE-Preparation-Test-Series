/*
Bruteforce Approach:
Time Complexity: O(n²)
Space Complexity: O(1)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
Better Approach:
Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> visitedElems;
        visitedElems.insert(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(visitedElems.find(nums[i]) != visitedElems.end()) {
                return true;
            }
            visitedElems.insert(nums[i]);
        }
        return false;
    }
};
