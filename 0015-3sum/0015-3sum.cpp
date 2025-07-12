class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        /// two sum + sort
        sort(nums.begin(), nums.end());

        for(int i=0 ; i<nums.size()-1;i++){

            if(i>0 && nums[i] == nums[i-1])
            continue;

            int s=i+1;
            int e = nums.size()-1;
            int f = -1*nums[i];
            while(s<e){
              
              if( nums[s]+nums[e]==f){
                vector<int>res;
                

                res.push_back(nums[i]);
                res.push_back(nums[s]);
                res.push_back(nums[e]);
                ans.push_back(res);
                
                s++;
                e--;

                // ho skta hai ki aur ek barr aa jae
                while(s<e && nums[s]==nums[s-1] ) s++;
                while(s<e && nums[e]==nums[e+1]) e--;
              }
              else if (nums[s]+nums[e]<f){
                s++;
              }else{
                e--;
              }
            }
        }
        return ans;

        
    }
};