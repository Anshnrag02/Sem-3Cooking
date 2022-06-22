class Solution {
public:
    string a , b;
    int n , m;
    int dp[1001][1001];
    
    int f(int n , int m){
        if(m==0){
            return dp[n][m]=1;
        }
        if(n==0){
            return dp[n][m]=0;
        }
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(a[n-1]==b[m-1]){
            dp[n][m]=f(n-1,m)+f(n-1,m-1);
        }
        else
            dp[n][m]=f(n-1,m);
        
        return dp[n][m];
        
        
    }
    
    int numDistinct(string s, string t) {
        a=s;b=t;
        n=a.length();
        m=b.length();
        for(int i = 0 ; i <=n ; ++i){
            for(int j = 0; j <=m ; ++j){
                dp[i][j]=-1;
            }
        }
        int ans =  f(n,m);
        return ans;
    }
};