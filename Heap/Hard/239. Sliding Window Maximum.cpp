/*
Time Complexity: O(n log k)
Space Complexity: O(k)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        unordered_multiset<int> deleted;
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }
        vector<int> ans;
        ans.push_back(pq.top());
        for (int i = 1; i + k - 1 < nums.size(); i++) {
            if (pq.top() == nums[i - 1]) {
                pq.pop();
            } else {
                deleted.insert(nums[i - 1]);
            }
            pq.push(nums[i + k - 1]);
            while (deleted.find(pq.top()) != deleted.end()) {
                deleted.erase(deleted.find(pq.top()));
                pq.pop();
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
};
