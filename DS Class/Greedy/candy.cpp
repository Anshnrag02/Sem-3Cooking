class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        
        if(n==1){
            return 1;
        }
        vector<int>v(n,1);
        for(int i = 1 ; i<n ; ++i){
            if(a[i]>a[i-1]){
                v[i]=max(v[i-1]+1,v[i]);
            }
        }
        for(int i = n-2 ; i>=0 ; --i){
            if(a[i]>a[i+1]){
                v[i]=max(v[i+1]+1,v[i]);
            }
        }       
        int sum = 0;
        for(auto x:v)
            sum+=x;
        return sum;
    }
};