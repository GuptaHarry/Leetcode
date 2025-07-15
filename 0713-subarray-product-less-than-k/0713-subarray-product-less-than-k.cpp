class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

     // brute approahc O(n2)
     // optimsied approach  -> two pointers 

     int s =0,e=0;
     int prod =1;
     int count=0;

     while(e<nums.size()){
 // decide which pointers to increment and decremnt
        prod*=nums[e];

        while(prod>=k && s<=e){
            prod/=nums[s];
            s++;
        }
        count+= 1+ (e-s);
        e++;

     }    
     return count;
    }

};