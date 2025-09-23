class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        vector<int>s1;
        vector<int>s2;

        version1+='.';
        version2+='.';
        int i =0;
        int i1=0;
        while(i1<version1.size()){

            if(version1[i1]!='.')
            i1++;
            else{
                s1.push_back(stoi(version1.substr(i,i1-i)));
                i1++;
                i=i1;
            }
        }
 int j =0;
        int j1=0;
        while(j1<version2.size()){

            if(version2[j1]!='.')
            j1++;
            else{
                s2.push_back(stoi(version2.substr(j,j1-j)));
                j1++;
                j=j1;
            }
        }


        i1=0;
        j1 =0;

        while(i1<s1.size() && j1<s2.size()){
                
                if(s1[i1]<s2[j1])
                return -1;
                else if ( s1[i1]>s2[j1])
                return 1;
                else
                {
                   i1++;
                   j1++;
                }
        }
         // check versions 
        
         if(i1==s1.size() && j1==s2.size())
         return 0;
         else
         {
             if(s2.size()>s1.size()){
                 int k = s2.size()-s1.size();
                 while(k--)
                 s1.push_back(0);


                 while(i1<s1.size() && j1<s2.size()){
                    if(s1[i1]<s2[j1])
                    return -1;
                    else if (s1[i1]>s2[j1])
                    return 1;
                    else{
                        i1++;
                        j1++;
                    }
                 }
                 return 0;
             }
             else{
                if(s1.size()>s2.size()){
                 int k = s1.size()-s2.size();
                 while(k--)
                 s2.push_back(0);


                 while(i1<s1.size() && j1<s2.size()){
                    if(s1[i1]<s2[j1])
                    return -1;
                    else if (s1[i1]>s2[j1])
                    return 1;
                    else{
                        i1++;
                        j1++;
                    }
                 }
                 return 0;
             }
         }
         }

 return 0;
    }
};