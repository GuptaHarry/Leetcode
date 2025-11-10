class Solution {
public:
    int arrangeCoins(int n) {
        

        int s = 1,e=n;
        int ans=0;
        while(s<=e){

            int mid = s+(e-s)/2;

            if(mid <=2LL*n/(mid+1)){
            ans = mid;
            s = mid+1;
            }
            else
            e=mid-1;
        }
        return ans;
    }
};