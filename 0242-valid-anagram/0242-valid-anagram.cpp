class Solution {
public:
    bool isAnagram(string s, string t) {


        vector<int>a1(26,0);
        vector<int>a2(26,0);

        for(int i=0;i<s.size();i++)
        a1[s[i]-'a']++;

        for(int i=0;i<t.size();i++)
        a2[t[i]-'a']++;

        for(int i=0;i<26;i++)
        {
            if(a1[i]!=a2[i])
            return false;
        }
        return true;
    }
};