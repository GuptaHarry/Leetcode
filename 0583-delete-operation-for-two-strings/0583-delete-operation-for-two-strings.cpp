class Solution {
public:
    int minDistance(string s1, string s2) {
        
          vector<int>dp(s2.size()+1,0);
        int prev , curr;
        for(int i=1;i<=s1.size();i++){
            
         prev=0,curr=0;   
        for(int j=1 ; j<=s2.size();j++){
            prev =curr;
            curr = dp[j];
            
            if(s1[i-1]==s2[j-1])
            dp[j]=1+prev;
            else
            dp[j]=max(dp[j],dp[j-1]);
        }
    }
    int lcs = dp[s2.size()];
    int insertions = s2.size()-lcs;
    int deletions = s1.size()-lcs;
    return insertions+deletions;
    }
};