class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        if(k<0)
        return 0;
        unordered_map<int,int>m;

        for(int i=0;i<nums.size();i++){
           m[nums[i]]++;
        }

 int count =0;
        for(auto it : m){

            int x =  it.first;
            if(k==0){
                if(it.second>1)
                count++;
            }
            else{
                if(m.find(x+k)!=m.end())
                count++;
            }

        }
        return count;
    }
};