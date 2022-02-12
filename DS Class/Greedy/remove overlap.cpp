class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n = a.size();
        for(int i = 0 ; i < n ; ++i){
            swap(a[i][0],a[i][1]);
        }
        sort(a.begin(),a.end());
        int end= a[0][0];
        int ans = 0;
        for(int i = 1; i<n; ++i){
            if(a[i][1]<end){
                ans++;    
            }
            else{
                end = a[i][0];
            }
        }
        return ans;
    }
};