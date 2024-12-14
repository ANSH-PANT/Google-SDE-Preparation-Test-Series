/*
Time Complexity: O(klogn+n)
Space Complexity: O(n)
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int n : nums) {
            pq.push(n);
        }
        long int mod = 1000000007, i = 0, ans = 1;
        while (i < k) {
            int m = pq.top();
            pq.pop();
            pq.push(m + 1);
            i++;
        }
        while (pq.size()) {
            ans = (ans * pq.top()) % mod;
            pq.pop();
        }
        return ans % mod;
    }
};
