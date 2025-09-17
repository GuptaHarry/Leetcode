class Solution {
public:
    int longestPalindromeSubseq(string s) {

        // code here
        string s2 = s;
        reverse(s2.begin(),s2.end());
        // optimsied
         vector<int>dp(s.size()+1,0);
         int prev,curr;
         
         for(int i=1;i<=s.size();i++){
             
         prev=0,curr=0;
         for(int j=1;j<=s.size();j++){
             
             /// intialse
             prev = curr;
             curr = dp[j];
             if(s[i-1]==s2[j-1])
             dp[j]=1+prev;
             else
             dp[j]=max(dp[j],dp[j-1]);
         }
         }
         return dp[s.size()];
    }
};