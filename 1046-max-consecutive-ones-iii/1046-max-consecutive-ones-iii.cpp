class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int ans = 0;
        int count =0;

        int s =0 , e=0;
        while(e<nums.size()){

            if(nums[e]==0 && count<k){
                ans = max(ans,e-s+1);
                count++;
                e++;
            }
            else if( nums[e]==1){
                ans = max(ans,e-s+1);
                e++;
            }else{
                // reset 
                s++;
                e=s;
                count=0;
            }
        }
        return ans;
    }
};