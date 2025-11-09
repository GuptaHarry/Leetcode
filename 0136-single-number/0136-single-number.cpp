class Solution {
public:
    int singleNumber(vector<int>& nums) {
        

        sort(nums.begin(),nums.end());
        // pattern recog. 
        // before single it is : even-odd
        // after single it is  : odd -even  point where pattern breaks.

       int s = 0 , e= nums.size()-1;

       while(s<e && e<nums.size()){
        int mid = s + (e-s)/2;
         // make eve n
         if(mid%2!=0)
         mid--;

         if(nums[mid]==nums[mid+1]){
            // pattenr iis correct break more on fronnt.
            s = mid+2;
         }
         if(nums[mid]!=nums[mid+1]){
             // paatenr break; go lefty 
             e = mid;
        }
       }

       return nums[s];

    }
};