class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        

        int s=0, len=0;
        unordered_map<int,int>bas;

        for(int  e=0;e<fruits.size();e++){
            bas[fruits[e]]++;  // store records

            while(bas.size()>2){
                bas[fruits[s]]--;  // remove that  count  from the basket of thaat tree            
                if(bas[fruits[s]]==0){  // if while rempving np frutis of that type is left then remoe that type of fruit from the baslet
                bas.erase(fruits[s]);

                }
                s++;
            }
            len = max(len,e-s+1);
        }
        return len;
    }
};