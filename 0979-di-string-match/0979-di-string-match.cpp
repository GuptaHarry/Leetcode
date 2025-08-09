class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int>ans;
        vector<int>res(s.size()+1,0);
        for(int i=0;i<res.size();i++)
        res[i]=i;

        int st =0, e=res.size()-1;
        for(int  i=0;i<s.size();i++){
            if(s[i]=='I')
            {
                ans.push_back(res[st]);
                st++;
            }
            else{
                ans.push_back(res[e]);
                e--;
            }
        }
        ans.push_back(res[st]);
        return ans;
    }
};