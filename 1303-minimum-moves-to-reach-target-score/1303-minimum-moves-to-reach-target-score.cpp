class Solution {
public:
  
    int minMoves(int target, int maxDoubles) {
         int moves =0;

         while(target>1 && maxDoubles>0){
            if(target%2==0){
                maxDoubles--;
                target = target/2;
                moves++;
            }else{
                target = target-1;
                moves++;
            }
         }

         if(target>1){
            moves += (target-1);
         }  
         return moves;  
    }
    
};