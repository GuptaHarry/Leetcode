class Solution {
public:
    int hammingWeight(int n) {

        int count=0;
        while(n!=1)
        {
            if(n%2)
            count++;

            n=n/2;
        }   
           return count+1;
        
    }
};