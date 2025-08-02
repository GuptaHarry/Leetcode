class Solution {
public:
   bool find(int index,int sum,vector<int>& nums,vector<vector<int>>&dp){
    // base 
    if(sum==0)
    return 1;
    if(index==nums.size())
    return 0;

  if(dp[index][sum]!=-1)
  return dp[index][sum];

    //skip case 
    if(sum<nums[index])
    return dp[index][sum]=find(index+1,sum,nums,dp);
    else
    return dp[index][sum]= find(index+1,sum-nums[index],nums,dp) || find(index+1,sum,nums,dp);
   }
    bool canPartition(vector<int>& nums) {

      int sum=0;
      for(int i=0;i<nums.size();i++)
      sum+=nums[i];
       
       if(sum%2!=0)
       return false;
      // top down 
      vector<vector<int>>dp(nums.size()+1,vector<int>(sum/2+1,-1));
      return find(0,sum/2,nums,dp);  
    } 
};