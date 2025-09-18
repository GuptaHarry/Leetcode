class Solution {
public:
 void find(int index, int n ,vector<int>& nums ,vector<vector<int>>&ans , vector<int>&temp   ){

    // base case 
    if(index == n){
        ans.push_back(temp);
        return ; 
    }

    // take 

    temp.push_back(nums[index]);
    find(index+1,n,nums,ans,temp);

    // not tkae 
    temp.pop_back();
    find(index+1,n,nums,ans,temp);
 }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        find(0,nums.size(),nums,ans,temp); // temp for storign the between values
        return ans;
    }
};