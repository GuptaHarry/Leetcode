class Solution {
public:

    int find( int sum , int index, vector<int>&coins, vector<vector<int>>&dp){
        /// base case
        
        if( sum==0)
        return 1;
         if(sum<0)
        return 0;
        if(index<0)
        return 0;
        
        if(dp[index][sum]!=-1)
        return  dp[index][sum];
        
        if(coins[index]>sum)
        return dp[index][sum]= find(sum,index-1,coins,dp);
        
        else 
        return
        dp[index][sum]=
        find(sum-coins[index],index,coins,dp)+find(sum,index-1,coins,dp);
        
       
        
        
        // return find(sum-coins[index],index,coins) + find(sum,index+1,coins);
    }

         int change(int sum, vector<int>& coins) {
        // code here.
        vector<vector<int>>dp(coins.size()+1,vector<int>(sum+1,-1));
        
        return find(sum , coins.size()-1,coins,dp);
    
    }
};
