class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n==1 && m==1)
        return 1;
        /// optimsied approahc 
        // for every cell need down element and right element 
        vector<int>dp(n,1);
        for(int i=m-2;i>=0;i--)
        for(int j=n-2;j>=0;j--){
            dp[j]=dp[j]+dp[j+1];
        }

       return dp[0];
    }
};