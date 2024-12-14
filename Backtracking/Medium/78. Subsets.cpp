/*
Time Complexity: O(2^n * n)
Space Complexity: O(2^n + n)
*/

class Solution {
private:
    void traverse(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& all) {
        if(i == nums.size()) 
          all.push_back(subset);
        else {
            traverse(nums, i+1, subset, all);          
            subset.push_back(nums[i]);
            traverse(nums, i+1, subset, all);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> all;
        vector<int> subset;
        traverse(nums, 0, subset, all);
        return all;
    }
};
