class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

     vector<int>dp(amount+1,INT_MAX);
     dp[0]=0;

       for(int i=coins.size()-1;i>=0;i--){
        for(int j=1;j<=amount;j++){

            // not take and take 
           int notTake = dp[j]; // skip coin
           int take= INT_MAX;
           if(j>=coins[i] && dp[j-coins[i]]!=INT_MAX){
            take = dp[j-coins[i]]+1;
           }
           dp[j]= min(notTake , take);
        }

       }
       return dp[amount]==INT_MAX?-1:dp[amount];   
    }
};