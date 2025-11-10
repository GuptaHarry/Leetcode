class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int start=0;
        int end=arr.size()-1;
        int mid=0,max=-1;
        while(start<=end){
            // mid = start +(end-start)/2
            mid = end+ (start-end)/2;


            if( arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                max=mid;
                break;
                
            }
            else if(arr[mid] < arr[mid-1]){
                // max=mid;
                end = mid-1;
            }
            else{
                // max=mid;
                start =mid+1;
            }
        }
        return max;
    }
};