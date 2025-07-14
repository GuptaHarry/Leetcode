class Solution {
public:
    int rob(vector<int>& nums) {
        
        // optimised version -3 
        int first = 0;
        int second =0;
        int ans =0;
        for(int i = nums.size()-1;i>=0;i--){
            ans = max( nums[i]+second , first);
            
            second = first;
            first = ans;
        }
        return ans;
    }
};