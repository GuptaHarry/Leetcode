class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int s=0,e=nums.size()-1;
        int ans =0;
        while(s<=e){

            int mid = s+(e-s)/2;
            if(mid==nums[mid]){
                // pattenr not broke 
                s=mid+1;
            }
            else if (mid!=nums[mid]){
                ans = mid;
                e = mid-1;
            }
        }
        // last case 
        if(nums.size()-1 == nums[nums.size()-1])
        return nums.size();
        // return -1;
        else
        return ans;
    }
};