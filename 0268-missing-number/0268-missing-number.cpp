class Solution {
public:
    int missingNumber(vector<int>& nums) {

     int n = nums.size();
      unordered_map<int,int>m;
      for(int i=0;i<nums.size();i++) 
       {
         m[nums[i]]=i;
       }

       for(int i=0;i<=nums.size();i++)
       if(m.find(i)==m.end())
       return i;

       return -1;
    }
};