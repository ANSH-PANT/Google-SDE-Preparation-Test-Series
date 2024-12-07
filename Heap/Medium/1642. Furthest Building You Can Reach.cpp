/*
Bruteforce Approach:
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
private:
    bool canReach(int mid, vector<int>& heights, int bricks, int ladders) {
        vector<int> jumps;
        for (int i = 0; i < mid; ++i) {
            if (heights[i + 1] > heights[i]) {
                int num = heights[i + 1] - heights[i];
                jumps.push_back(heights[i + 1] - heights[i]);
            }
        }
        if (jumps.size() <= ladders) {
            return true;
        }
        sort(jumps.begin(), jumps.end());
        int sum = 0;
        sum = accumulate(jumps.begin(), jumps.end() - ladders, sum);
        return (sum <= bricks);
    }

public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int low = ladders;
        int high = heights.size();
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (!canReach(mid, heights, bricks, ladders))
                high = mid;
            else
                low = mid + 1;
        }
        return low - 1;
    }
};

/*
Optimised Approach:
Time Complexity: O(n log k)
Space Complexity: O(k)
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < heights.size() - 1; ++i) {
            if (heights[i] < heights[i + 1]) {
                pq.push(heights[i + 1] - heights[i]);
                if (pq.size() > ladders) {
                    int smallest = pq.top();
                    pq.pop();
                    if (bricks < smallest) {
                        return i;
                    }
                    bricks -= smallest;
                }
            }
        }
        return heights.size() - 1;
    }
};
