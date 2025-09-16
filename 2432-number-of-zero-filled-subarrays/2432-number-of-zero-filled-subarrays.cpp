class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

       long long total =0;

       int s=0,e=0;
       while(e<nums.size()){
         if(nums[e]==0){
            total += (e-s)+1;
            // s++;
            e++;
         }else{
            
            e++;
            s=e;
         }
       }

       return total;
    }
};