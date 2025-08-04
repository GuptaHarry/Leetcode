class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int count=fruits.size();
        // since lengths are equal
        int  index=0;
        while(index<fruits.size()){
            
            for(int j=0;j<fruits.size();j++){
                if(baskets[j]>=fruits[index] && baskets[j]!=9999){
                    count--;
                   
                    baskets[j]=9999;

                    break;
                }
                
            }
              index++;
        }



        return count;
        
    }
};