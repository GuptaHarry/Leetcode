class Solution {
public:
    int maxPower(string s) {


      // find the maximum longest substring with one character
      if(s.size()==1)
      return 1;

      int ans =0;
      int st=0,e=1;
      while(e<s.size()){
        if(s[st]==s[e]){
            ans = max(ans , e-st+1);
            e++;
        }
        else{
            st=e;
            e++;
        }
      }

      if(ans==0)
      return 1;
      return ans;   
    }
};