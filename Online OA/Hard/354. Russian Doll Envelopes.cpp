/*
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        } 
        else {
            return a[0] < b[0];
        }
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++) {
            if (temp.back() < envelopes[i][1]) {
                temp.push_back(envelopes[i][1]);
            } 
            else {
                auto ind = lower_bound(temp.begin(), temp.end(), envelopes[i][1]) - temp.begin();
                temp[ind] = envelopes[i][1];
            }
        }
        return temp.size();
    }
};
