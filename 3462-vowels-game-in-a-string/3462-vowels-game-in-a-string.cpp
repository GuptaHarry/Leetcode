class Solution {
public:
  int find(string temp , bool turn){

     if(!turn){
        // alice 
        int maxOdd=-1;
        int count=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='a'|| temp[i]=='e'|| temp[i]=='i' || temp[i]=='o'||temp[i]=='u'){
                count++;
                if(count%2!=0)
                maxOdd=i;

            }
        }

        return maxOdd;
     }
     else{
        int maxEven=-1;
        int count=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='a'|| temp[i]=='e'|| temp[i]=='i' || temp[i]=='o'||temp[i]=='u'){
                count++;
                if(count%2==0)
                maxEven=i;

            }
        }

        return maxEven;
     }
  }
    bool doesAliceWin(string s) {
        

        bool turn = false; // for alice true for bob
        string temp = s;

        while( temp.size()!=0){

            if(!turn){
                // alice turn -> odd length substring
                int odd_index = find(temp,turn);
                if(odd_index==-1)
                return false;
                string res="";
                for(int i=odd_index+1;i<temp.size();i++)
                 res+=temp[i];

                 temp = res;
                 turn = !turn;
            }else{
                int even_index = find(temp,turn);
                    string res="";
                    if(even_index==-1)
                    return true;
                    for(int i=even_index+1;i<temp.size();i++)
                    res+=temp[i];

                    temp = res;
                    turn = !turn;
                }
            }
        
        return true;
    }
};