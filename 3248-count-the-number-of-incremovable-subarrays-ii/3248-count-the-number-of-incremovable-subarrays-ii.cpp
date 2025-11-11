
class Solution {
public:
    long long  incremovableSubarrayCount(vector<int>& nums) {
        
        long long ans =0;
        vector<int>pre,suf;
        for(int i=0;i<nums.size();i++){
            if(pre.empty() || nums[pre.back()]<nums[i])
            pre.push_back(i);
            else
            break;
        }

         for(int i=nums.size()-1;i>=0;i--){
            if(suf.empty() || nums[suf.back()]>nums[i])
            suf.push_back(i);
            else
            break;
        }

        // check for overlap 
        if(pre.size()+suf.size()>nums.size())
        return 1LL * nums.size() *(nums.size()+1)/2;
ans = pre.size()+suf.size();

        reverse(suf.begin(),suf.end());
        int i=0;
        int j=0;
        while(i<pre.size() && j<suf.size()){
            if(nums[pre[i]]<nums[suf[j]]){
                ans += (suf.size()-j);
                i++;
            }
            else
            j++;
        }
        return ans+1;
       
    }
};