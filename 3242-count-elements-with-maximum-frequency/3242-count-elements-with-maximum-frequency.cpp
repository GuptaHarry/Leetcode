class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

 
         unordered_map<int,int>m;
         int count=0;
         int maxF = INT_MIN;
         for(int i=0;i<nums.size();i++){
             m[nums[i]]++;
             

             if(maxF<m[nums[i]]){
                count=m[nums[i]];
                maxF = m[nums[i]];
             }

            else  if(maxF==m[nums[i]]){
                count+=m[nums[i]];
             }
         }
  
        
         return count;


    }
};