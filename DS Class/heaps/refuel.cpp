

class Solution {
public:
    int minRefuelStops(int target, int gas, vector<vector<int>>& a) {
        int n = a.size();
        a.push_back({target,0});
        int pos=gas;
        int cnt= 0;
        priority_queue<int>pq;
        for( int i = 0 ; i < a.size() ; ++i ){
            
            while(pos<a[i][0]){
                if(pq.empty()){
                    return -1;
                }
                pos+=pq.top();
                pq.pop();
                cnt++;
            }
            pq.push(a[i][1]);
        }
        
        return cnt;
    }
};