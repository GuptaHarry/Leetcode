class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        

          sort(nums.begin(),nums.end()); 
          vector<int>pre(nums.size(),0);
          pre[0]=nums[0];
          for(int i=1;i<nums.size();i++){
           pre[i]=nums[i]+pre[i-1];
          }
        vector<int>ans;
          for(int i=0;i<queries.size();i++){
            int sum=queries[i];
            int s =0,e=pre.size()-1;
            int val =0;
            while(s<=e){
                int mid = s+(e-s)/2;

                if(pre[mid]<=sum){
                    // ans.push_back(mid+1);
                    val =max(val,mid+1);
                    s=mid+1;
                    // break;

                }
                else
                e=mid-1;
                
                
            }
            ans.push_back(val);
          }
 return ans;
         


    }
};