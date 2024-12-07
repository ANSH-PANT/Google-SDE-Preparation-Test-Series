/*
Bruteforce Approach:
Time Complexity: O(n * 2^n)
Space Complexity: O(n * 2^n)
*/

class Solution {
private:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset;
        int i = 0;
        vector<int> subset;
        traverse(i, subset, nums.size(), powerset);
        return powerset;
    }
    
    void traverse(int i, vector<int>& subset, int n, vector<vector<int>>& powerset) {
        if(i == n) 
          powerset.push_back(subset);
        else {
            traverse(i+1, subset, n, powerset);
            subset.push_back(i);
            traverse(i+1, subset, n, powerset);
            subset.pop_back();
        }
    }
    
    bool isValid(vector<int> &subset) {
        for(int i = 1 ; i < subset.size(); i++) {
            if(abs(subset[i-1] - subset[i]) == 1) 
              return false;
        }
        return true;
    }
    
    int value(vector<int> & subset, vector<int> & nums) {
        int sum = 0;
        for(int i : subset) {
            sum += nums[i];
        }
        return sum;
    }

public:
    int rob(vector<int>& nums) {
        int maxVal = INT_MIN;
        vector<vector<int>> powerset = subsets(nums);
        for(vector<int>& subset : powerset) {
            if(isValid(subset)) {
                maxVal = max( value(subset, nums), maxVal);
            }
        }
        return maxVal;
    }
};

/*
Time Complexity: O(n * 2^n)
Space Complexity: O(n)
*/

class Solution {
private:
    void traverse(int i, vector<int>& subset, int n, int& maxVal, vector<int>& nums) {
        if(i == n) {
            if(isValid(subset)) {
                maxVal = max( value(subset, nums), maxVal);
            }
        } 
        else {
            traverse(i+1, subset, n, maxVal, nums);
            subset.push_back(i);
            traverse(i+1, subset, n, maxVal, nums);
            subset.pop_back();
        }
    }
    
    bool isValid(vector<int> &subset) {
        for(int i = 1 ; i < subset.size(); i++) {
            if(abs(subset[i-1] - subset[i]) == 1) return false;
        }
        return true;
    }
    
    int value(vector<int> & subset, vector<int> & nums) {
        int sum = 0;
        for(int i : subset) {
            sum += nums[i];
        }
        return sum;
    }

public:
    int rob(vector<int>& nums) {
        int maxVal = INT_MIN;
        int i = 0;
        vector<int> subset;
        traverse(i, subset, nums.size(), maxVal, nums);
        return maxVal;
    }
};

/*
Better Approach:
Time Complexity: O(1.62^n)
Space Complexity: O(n)
*/

class Solution {
private:
    int f1(int n, const vector<int>& nums) {
        if(n == 0) 
          return 0;
        if(n == 1) 
          return nums[0];
        return max( f1(n-1, nums), nums[n-1] + f1(n-2, nums) );
    }

public:
    int rob(vector<int>& nums) {
        return f1(nums.size(), nums);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
private:
    int f1(vector<int>& nums, int n, unordered_map<int, int> &f1tbl) {
        if(f1tbl.find(n) == f1tbl.end()) {
            if(n == 0) 
              f1tbl[n] = 0;
            else if(n == 1) 
              f1tbl[n] = nums[0];
            else {
                f1tbl[n] = max(f1(nums, n-1, f1tbl), nums[n-1] + f1(nums, n-2, f1tbl));
            }
        }
        return f1tbl[n];
    }

public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> f1tbl;
        return f1(nums, nums.size(), f1tbl);
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int f1nMINUS2 = 0;
        int f1nMINUS1 = nums[0];
        for(int n = 2; n <= nums.size(); n++) {
            int curr = max( f1nMINUS1, nums[n-1] + f1nMINUS2 );
            f1nMINUS2 = f1nMINUS1;
            f1nMINUS1 = curr;
        }
        return f1nMINUS1;
    }
};
