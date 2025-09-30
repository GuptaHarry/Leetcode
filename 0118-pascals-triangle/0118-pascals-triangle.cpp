class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        

        vector<vector<int>>ans;
        vector<int>t(1,1);
        ans.push_back(t );
         if(numRows ==1)
         return ans;
        for(int i=2;i<=numRows;i++){
            
              int n = ans[ans.size()-1].size();
              // size of preovios array 
              vector<int>temp(n+1,1);
              vector<int>prev = ans.back();
              for(int j=1;j<=temp.size()-2;j++){
                 temp[j] = prev[j-1]+prev[j];
              }
              ans.push_back(temp);
        }

        return ans;
    }
};