/*
Bruteforce Approach:
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
    int n;

private:
    int trappedWater(int i, vector<int>& height) {
        int leftWall = height[i - 1], rightWall = height[i + 1];
        for (int j = i - 2; j >= 0; --j)
            leftWall = max(leftWall, height[j]);
        for (int j = i + 2; j < n; ++j)
            rightWall = max(rightWall, height[j]);
        return max(0, min(leftWall, rightWall) - height[i]);
    }

public:
    int trap(vector<int>& height) {
        n = height.size();
        int result = 0;
        for (int i = 1; i < n - 1; ++i) {
            result += trappedWater(i, height);
        }
        return result;
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
    int n;
    vector<int> prefixmax;
    vector<int> suffixmax;

private:
    int trappedWater(int i, vector<int>& height) {
        int leftWall = prefixmax[i - 1], rightWall = suffixmax[i + 1];
        return max(0, min(leftWall, rightWall) - height[i]);
    }

public:
    int trap(vector<int>& height) {
        n = height.size();
        prefixmax.resize(n);
        prefixmax[0] = height[0];
        for (int i = 1; i < n; ++i)
            prefixmax[i] = max(prefixmax[i - 1], height[i]);
        suffixmax.resize(n);
        suffixmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suffixmax[i] = max(suffixmax[i + 1], height[i]);
        int result = 0;
        for (int i = 1; i < n - 1; ++i) {
            result += trappedWater(i, height);
        }
        return result;
    }
};
