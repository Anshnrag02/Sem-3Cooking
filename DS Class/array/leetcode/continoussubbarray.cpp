class Solution {
public:
    
    
    
    bool checkSubarraySum(vector<int>& a, int k) {
        int n =  a.size();
        
        if(n<=1)
            return false;
        
        vector<int>b(n+1);
        vector<bool>m(k,false);
        b[0]=0;
        for(int i = 0 ; i < n ; ++i){
            b[i+1]=a[i]+b[i];
            
            if(m[b[i+1]%k]==1){
                return 1;
            }
            m[b[i]%k]=1;
        }
        
        
        return false;
    }
};