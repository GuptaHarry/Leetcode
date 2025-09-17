class Solution {
public:

  int find(int index , int amount ,vector<int>& coins , vector<vector<int>>&dp ){

      if(amount==0)
      return 0;

      if(index==coins.size())
      return INT_MAX;  // no coins left

      if(dp[index][amount]!=-1)
      return  dp[index][amount];


      int notTake = find(index+1,amount,coins,dp);


      int take = INT_MAX;
      if(coins[index]<=amount)
      take = find(index,amount-coins[index],coins,dp);
      if(take != INT_MAX)
      take+=1;
   return dp[index][amount] = min(notTake , take);
        
  }
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = find(0,amount,coins,dp);
        // return dp[coins.size()][amount];
          return (ans == INT_MAX ? -1 : ans);
    }
};