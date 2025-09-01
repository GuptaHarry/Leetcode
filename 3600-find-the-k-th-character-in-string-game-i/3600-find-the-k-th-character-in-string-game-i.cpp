class Solution {
public:
    char kthCharacter(int k) {
        
        string ans = "a";
        while(ans.size()<k){
            string temp="";
            for(int i=0;i<ans.size();i++){
                int c = ans[i];
                if(c==122)
                c=97;
                else
                c++;
                char d = c;
                temp+=d;
            }
            ans+=temp;
        }
        return ans[k-1];
    }
};