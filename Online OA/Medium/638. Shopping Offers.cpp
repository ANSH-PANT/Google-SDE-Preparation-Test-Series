class Solution {
    int calculatePrice(vector<int>& price, vector<int>& needs) {
        int ans = 0;
        for (int i = 0; i < price.size(); i++) {
            ans += (price[i] * needs[i]);
        }
        return ans;
    }

    int helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& map) {
        string needString = "";
        for (int i = 0; i < needs.size(); i++) {
            needString += (to_string(i) + " " + to_string(needs[i]));
        }
        if (map.find(needString) != map.end())
            return map[needString];
        int minPrice = calculatePrice(price, needs);
        for (int i = 0; i < special.size(); i++) {
            vector<int> temp;
            int j;
            for (j = 0; j < special[i].size() - 1; j++) {
                if (needs[j] < special[i][j])
                    break;
                temp.push_back(needs[j] - special[i][j]);
            }
            if (j == needs.size()) {
                int ans = helper(price, special, temp, map);
                ans += special[i][j];
                if (ans < minPrice) {
                    minPrice = ans;
                }
            }
        }
        map[needString] = minPrice;
        return minPrice;
    }

public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> map;
        return helper(price, special, needs, map);
    }
};
