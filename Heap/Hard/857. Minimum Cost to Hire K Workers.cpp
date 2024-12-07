/*
Time Complexity: O(n log n + n log k)
Space Complexity: O(n)
*/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        multimap<double, int> ratioQuality;
        for (int i = 0; i < quality.size(); ++i) {
            ratioQuality.insert({1.0 * wage[i] / quality[i], quality[i]});
        }
        int qualitySum = 0;
        double res = DBL_MAX;
        priority_queue<int> pq;
        auto it = ratioQuality.begin();
        while (k--) {
            pq.push(it->second);
            qualitySum += it->second;
            it++;
        }
        it--;
        res = min(res, qualitySum * it->first);
        it++;
        while (it != ratioQuality.end()) {
            pq.push(it->second);
            qualitySum += it->second;
            qualitySum -= pq.top();
            pq.pop();
            res = min(res, qualitySum * it->first);
            it++;
        }
        return res;
    }
};
