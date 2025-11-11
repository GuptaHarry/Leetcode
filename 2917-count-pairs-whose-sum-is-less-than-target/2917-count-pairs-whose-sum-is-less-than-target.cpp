class Solution {
public:
    int countPairs(vector<int>& nums, int target) {

         int ans =0;
    int s = 0;
    int  e=nums.size()-1;
    sort(nums.begin(),nums.end());
    while(s<e){

        if(nums[s]+nums[e]>=target){
            // target ko kam krna hai
            e--;
        }
        else{
            ans+=(e-s);
            s++;
        }

       
    }
    return ans;  
    }

    // -1 1 1 2 3  t=2
   
};