//code1 using Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max_sum=nums[0];
      for(int i=0;i<nums.size();i++){
          sum=sum+nums[i];
         max_sum=max(max_sum,sum);
               if(sum<0){
        sum=0;
               }
           }
      return max_sum;
    }
};

//code2
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int curr_sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > curr_sum) {
                curr_sum = sum;
            }
            if (sum < 0)
                sum = 0;
        }
        return curr_sum;
    }
};
