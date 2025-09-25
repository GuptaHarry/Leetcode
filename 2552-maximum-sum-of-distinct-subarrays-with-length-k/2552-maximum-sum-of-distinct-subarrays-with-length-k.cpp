class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        

        int s =0 , e=0 ;
        long long ans =0;
        long long temp=0;
        unordered_map<int,int>m;

        while(e<nums.size()){

            // add the elee,mt 
            temp+=nums[e];
            m[nums[e]]++;
            

            // shrink if exceec duplicates 
            while(m[nums[e]]>1){
                temp-=nums[s];
                m[nums[s]]--;
                s++;
            }


            // if sizee is more then shrink
            if(e-s+1 > k){
                temp-=nums[s];
                m[nums[s]]--;
                s++;
            }

            if(e-s+1==k)
            ans = max(ans,temp);

            e++;
        }
        return ans;
    }
};