#include<bits/stdc++.h>

using namespace std;

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int dp[n+1];
    dp[1]=0;

    for(int i = 2 ; i <=n ; ++i){
        dp[i]=INT_MAX;
        if(i%2==0)
            dp[i]=min(dp[i],dp[i/2]+1);
        if(i%3==0)
            dp[i]=min(dp[i],dp[i/3]+1);
        dp[i]=min(dp[i],dp[i-1]+1);
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout<<dp[n];

	return 0;
}