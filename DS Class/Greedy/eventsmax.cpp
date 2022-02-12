class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int day = 1;
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = events.size();
        int count = 0;
        int i = 0;
        sort(events.begin(),events.end());
        while(i<n || pq.size()>0){
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
            
            while(i<n && events[i][0]==day){
                pq.push(events[i++][1]);
            }
            
            if(pq.size()>0){
                pq.pop();
                count++;
            }
            day++;
        }
        return count;
    }
};