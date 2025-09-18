class Solution {
public:
 int find(int n , int m ,vector<int>& nums1, vector<int>& nums2 , int &ans , 
 vector<vector<int>>&dp ){

    if(n==0 || m==0)
    return 0;

    if(dp[n][m]!=-1)
    return dp[n][m];

    int len =0;
    if( nums1[n-1]==nums2[m-1]){
        len = 1 + find(n-1,m-1,nums1,nums2,ans,dp);
        ans = max(ans,len);
    }

    // necessaroy to make callls 
    find(n-1,m,nums1,nums2,ans,dp);
    find(n,m-1,nums1,nums2,ans,dp);
    return dp[n][m]=len;
 }
    int findLength(vector<int>& nums1, vector<int>& nums2) {

      int ans = 0;
      vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
      find(nums1.size(),nums2.size(),nums1,nums2,ans,dp);

      return ans;   
    }
};