/*
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;
        sort(asteroids.begin(), asteroids.end());
        for (auto i : asteroids) {
            if (i <= m)
                m += i;
            else
                return false;
        }
        return true;
    }
};
