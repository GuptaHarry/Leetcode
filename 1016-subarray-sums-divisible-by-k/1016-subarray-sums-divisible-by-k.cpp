class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        // optimsed approah O(n) O(n)
        unordered_map<int,int>m;
        m[0]=1;
        int total =0;
        int sum=0;
        int rem=0;
        for(int i=0 ;i<nums.size();i++){
            // while(nums[i]<0)
            // nums[i]+=k;
          
          sum+=nums[i];
          rem= sum%k;
          
          if(rem<0)
          rem +=k;
          if(m.count(rem)){
            total+=m[rem];
            m[rem]++;
          }
          else{
            m[rem]=1;
          }
             

        }
        return total;
    }
};