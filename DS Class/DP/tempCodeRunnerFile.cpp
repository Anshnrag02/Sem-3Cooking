#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&dp, int n){
	if(n<=3){
		return n;
	}
	if(dp[n]==0){
		dp[n]=max(n,solve(dp,n/2)+solve(dp,n/3)+solve(dp,n/4));
	}
	return dp[n];
}


int main() {
	
	// your code here
	int n; cin>>n;
	vector<int>dp(n+1,0);
	n = solve(dp,n);
	cout<<n;
	return 0;
}