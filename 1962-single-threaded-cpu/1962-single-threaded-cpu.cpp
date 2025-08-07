class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>ans;
        for(int i=0;i<tasks.size();i++)
        tasks[i].push_back(i);   // add order no to tasks.

        // sort on the basis of enqueu time
        sort(tasks.begin(),tasks.end());
        // startwith inita enqueu time 
        long long  timer = tasks[0][0];
        int  i=0 ;// traverse
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
      
      // push all into min-heap 
      while(!pq.empty() || i<tasks.size()){

        // main conditin
        while(i<tasks.size() && timer>=tasks[i][0]){
        pq.push({tasks[i][1],tasks[i][2]});
        i++;
      }

      // heap empty
      if(pq.empty()){
        timer=tasks[i][0];
      }
      else{
         ans.push_back(pq.top().second);
         timer+=pq.top().first;
         pq.pop();
      }
      }
      return ans;
    }
};