class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        
        int n = a.size();
        
        vector<int>b(n+1);
        
        b[0]=0;
        
        for(int i = 1; i<=n; ++i){
            b[i]=a[i-1]+b[i-1];
            b[i]%=k;
        }
        
        if(n==1)
            return false;
        if(n==2)
            return (a[0]+a[1])%k==0;
        
        unordered_set<int>s;
        
        for(int i = 2; i<=n ; ++i){
            s.insert(b[i-2]);
            if(s.find(b[i])!=s.end())
                return 1;    
        }
        return 0;
    }
};