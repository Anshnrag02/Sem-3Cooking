class Solution {
public:
    
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>>a(n+1,vector<int>(2));
        for( int i = 0 ; i <= n ; ++i ){
            a[i][0]=max(0,i-ranges[i]);
            a[i][1]=min(n,i+ranges[i]);
        }
        sort(a.begin(),a.end(),[&](vector<int>a,vector<int>b){
            if(a[0]<b[0] or (a[0]==b[0] and a[1]>b[1]))
                return 1;
            return 0;
        });
        int pos = 0;
        int cnt = 0;
        
        priority_queue<int>pq;
        
        for(int i = 0 ; i <=n; ++i ){
            
            if(pos<a[i][0]){
                if(pq.empty() or pq.top()<a[i][0])
                    return -1;
                pos=pq.top();
                pq.pop();
                cnt++;
                
            }
            if(a[i][1]>pos)
                pq.push(a[i][1]);
        }
        if(pos<n){
            if(pq.empty() or pq.top()<n)
                    return -1;
            return cnt+1;
        }
        
        return cnt;
        
    }
};