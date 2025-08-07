class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        // sort om the basis of maximum units of each unit
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<boxTypes.size();i++) 
        pq.push({boxTypes[i][1],boxTypes[i][0]});  // unit , boxes

        int unit=0;
        while(!pq.empty() && truckSize!=0){
            pair<int,int>temp;
            temp=pq.top();
            pq.pop();
            if(truckSize>=temp.second){
                truckSize-=temp.second;
                unit+=(temp.first*temp.second);
            }else{
                while(truckSize){
                  truckSize-=1;
                  temp.second-=1;
                  unit+=temp.first;
                }
            }
        }
        return unit;
    }
};