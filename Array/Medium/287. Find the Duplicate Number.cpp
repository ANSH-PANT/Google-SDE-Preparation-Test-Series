/*
Bruteforce Approach:
Time Complexity: O(n²)
Space Complexity: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int domainElem = 1; domainElem <= nums.size(); domainElem++) {
            if(isrepeated(domainElem, nums)) return domainElem;
        }
    }
private:
    bool isrepeated(int domainElem, vector<int>& nums) {
        bool found = false;
        for(int elem : nums) {
            if(elem == domainElem) {
                if(found == false) found = true;
                else return true;
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
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1])
                return nums[i];
        }
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums) {
            if(freq.find(num) == freq.end()) {
                freq[num] = 0;
            }
            freq[num]++;
        }
        for(int num : nums) {
            if(freq[num] > 1) return num;
        }
    }
};

/*
Space Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int elem = nums[i];
            while(elem != i && elem != nums[elem]) {
                swap(nums[i], nums[elem]);
                elem = nums[i];
            }
        }
        return nums[0];
    }
};
