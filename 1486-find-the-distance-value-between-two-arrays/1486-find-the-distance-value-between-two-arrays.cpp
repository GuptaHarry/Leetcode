class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        

        // 4 5 8 
        // 1 8 9 10
        // 0 1 2 3

        // sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());

int ans =0;
        for(int i=0;i<arr1.size();i++){
            int s = 0,e=arr2.size()-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                // int x = arr1[i]-d;
                // int  y = arr1[i]+d;

                // if(arr2[mid]>x)
                // s=mid+1;
                // if(arr2[mid]<y)

                if( abs(arr1[i]-arr2[mid])<=d){
                    ans++;
                    break;
                }

                if(arr2[mid]>arr1[i])
                 e=mid-1;
                 else
                 s=mid+1;
            }
        }
        return arr1.size()-ans;
    }
};