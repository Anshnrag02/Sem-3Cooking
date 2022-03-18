int solve(int i = 0 , int j =n-1)
{
    if(i>j)
        return 0;
    
    if(dp[i][j]==-1){
        dp[i][j]=max(a[i]+min(solve(i+2,j),solve(i+1,j-1)),a[j]+min(solve(i+1,j-1),solve(i,j-2)));
    }
    return dp[i][j];
}
