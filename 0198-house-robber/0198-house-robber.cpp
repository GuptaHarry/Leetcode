class Solution {
public:
int find(int index, vector<int>&dp , vector<int>nums , int n ){
      if(index >=n)
      return 0;

      if(dp[index]!=-1)
      return dp[index];

      dp[index]= max ( nums[index]+ find(index+2 , dp , nums,n) ,
      find(index+1,dp,nums,n));
      return dp[index];
}
    int rob(vector<int>& nums) {

     // top down appraoch 
     // variable changing -> index only => 1D dp required 
     // max index reachable ->   size +2 
     vector<int>dp(nums.size()+2 ,-1);
     dp[nums.size()+1] = dp[nums.size()]=0;

     return find(0, dp, nums,nums.size());
    }
};