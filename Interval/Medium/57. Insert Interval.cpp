/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        int start = newInterval[0];
        if (i < intervals.size() && intervals[i][0] < start)
            start = intervals[i][0];
        while (i < intervals.size() && intervals[i][1] <= newInterval[1])
            i++;
        int end = newInterval[1];
        if (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            end = intervals[i][1];
            i++;
        }
        ans.push_back({start, end});
        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
