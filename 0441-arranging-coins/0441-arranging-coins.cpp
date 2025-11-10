class Solution {
public:
    int arrangeCoins(int n) {
        
        int val = n;

 if(n==1)
 return 1;
        int ans=0;
        for(int i=1;i<n;i++){
          
          if(val<i)
          break;
          val-=i;
          ans++;

        }
        return ans;
    }
};