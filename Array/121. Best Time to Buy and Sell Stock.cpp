//code 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
int first_price=0;int profit=INT_MAX;
for(auto i:prices){
    profit=min(i,profit);
    first_price=max(first_price,i-profit);
}
return first_price;
    }
};
//code 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int first_price=prices[0];
int profit= INT_MIN;
for(int i=1;i<prices.size();i++){
       profit= max(profit ,prices[i]-first_price);
       first_price=min(first_price,prices[i]);
}
if(profit<0){
    return 0;
    }
return profit;
    }
};
