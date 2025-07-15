class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        // optimised approach -> O(n) O(n)
        unordered_map<int,int>m;
        m[0]=1;
        int total =0 , sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(m.count(sum-k)){
                total+=m[sum-k];
                m[sum]++; //  it alread y intialsies it .
            }
            else{
                // m[sum]=1;
                m[sum]++;
            }
        }
        return total;
    }
};