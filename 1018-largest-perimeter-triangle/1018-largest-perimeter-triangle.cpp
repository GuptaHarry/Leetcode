class Solution {
public:
bool check(int a ,int b ,int c){
    if( (a+b)>c && (b+c)>a && (a+c)>b)
    return true;

    return false;
}
    int largestPerimeter(vector<int>& nums) {
        int per = 0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=2;i--){

            if(check(nums[i],nums[i-1],nums[i-2])){
           per = max(per,nums[i]+nums[i-1]+nums[i-2] );
            }
        }
 return per;
    } 
};