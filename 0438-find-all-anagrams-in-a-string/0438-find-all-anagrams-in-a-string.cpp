class Solution {
public:
    vector<int> findAnagrams(string s, string p) {


        vector<int>ans;
        vector<int>a1(26,0);
        for(int i=0;i<p.size();i++)
        a1[p[i]-'a']++;
         
         vector<int>a2(26,0);

         int st =0 , e=0;
         while(e<s.size()){

            // add 
            a2[s[e]-'a']++;

            // shrink if req
            if(e-st+1 > p.size()){
                a2[s[st]-'a']--;
                st++;
            }

            if(e-st+1 == p.size() && a1==a2)
            ans.push_back(st);

            e++;
         }
         return ans;

         


        
        
    }
};