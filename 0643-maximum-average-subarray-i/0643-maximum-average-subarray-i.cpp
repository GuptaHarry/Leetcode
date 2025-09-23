class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

      double ans =0;
      double sum = 0;

      for(int i=0;i<k;i++)
      sum+=nums[i];

      ans =  sum/(double)k;

    for(int i=k;i<nums.size();i++){
        sum-=nums[i-k];// shortne the widow 
        sum+=nums[i];  // incremese the window 

        ans = max(ans , sum/(double)k);
    }
    return ans;
    }
};