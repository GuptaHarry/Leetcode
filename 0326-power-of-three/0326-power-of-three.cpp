class Solution {
public:
    bool isPowerOfThree(int n) {


         // divide with largest power of three within 432bit range 
         if(n<=0)
         return false;
         return 1162261467%n==0; 
    }  
};