class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        

        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++)
        m[arr[i]]=i;

        for(int i=0;i<arr.size();i++){
            if(m.find(2*arr[i])!=m.end() && i!=m[2*arr[i]])
            return true;
        }
        return false;
    }
};