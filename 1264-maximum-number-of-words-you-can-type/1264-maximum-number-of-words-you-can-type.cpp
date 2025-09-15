class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        vector<int>lower(26,0);
        for(int i=0;i<brokenLetters.size();i++)
        lower[ brokenLetters[i]-'a']++;
        
        bool fault = true;
        int count=0;
        for(int i=0;i<text.size();i++){
         
          if( text[i]!=' ' && lower[text[i]-'a'])
          fault = false;
          else  if( text[i] ==' '){
            if(fault)
            count++;

            // reset
            fault = true;
          }
        }
        if(fault)
        count++;
        return count;
    }
};