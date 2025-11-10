class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        if(nums.size()==1)
        return 0;

        int s = 0 , e =nums.size()-1;
 int ans =-1;
         while(s<=e){
            int mid = s + (e-s)/2;


            if(mid==0){
                if(nums[mid]>nums[mid+1]){
                 ans=mid;
                 break;
                }
                else{
                    s=mid+1;
                    continue;
                }
                
            }

            if(mid==nums.size()-1){
                if(nums[mid]>nums[mid-1]){
                    ans=mid;
                    break;
                }
                else{
                    e=mid-1;
                    continue;
                }
            }
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                ans = mid;
                break;
            }

            if(nums[mid]<nums[mid+1]){
                s = mid+1;
            }
            else
            e = mid-1;
         }
         return ans;
    }
};