class Solution {
public:
    int maxFreqSum(string s) {

        vector<int>ans(26,0);

        for(int i=0 ; i<s.size();i++){

            ans[s[i]-'a']++;
        }

        int max_vowel = INT_MIN;
        int max_cons = INT_MIN;

         // for maximum consontnat 
       for(int i=0 ; i<ans.size();i++){

           if( ans[i]!=0){
               if ( i+'a' == 'a' || i+'a' == 'e' || i+'a' == 'i'|| i+'a' == 'o' || i+'a' == 'u' ){
                   max_vowel = max( max_vowel,ans[i]);
                   
               }
               else{
                   max_cons = max (max_cons , ans[i]);
               }
           }
       }

       if(max_vowel !=INT_MIN && max_cons !=INT_MIN){
            return max_vowel + max_cons;
       }
        else{

            if(max_vowel!=INT_MIN){
                return max_vowel;
            }
            else{
                return max_cons;
            }
        }
    }
};