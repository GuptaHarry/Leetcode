class Solution {
public:
 int find(vector<int>&v , int i,int j,vector<vector<int>>&dp){
    // base case 
    if(i+1==j)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];


    int res  = INT_MAX;
    for(int k =i+1 ; k<j;k++){
     res = min(res , v[i]*v[j]*v[k] + find(v,i,k,dp)+find(v,k,j,dp));
    }
    dp[i][j]=res;

    return dp[i][j];
 }
    int minScoreTriangulation(vector<int>& v) {
        vector<vector<int>>dp(v.size() , vector<int>(v.size(),-1));
         return find(v , 0,v.size()-1,dp);
    }
};