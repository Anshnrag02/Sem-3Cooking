#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int n ; 
	cin>>n;
	vector<int>a(n);
	
	for(auto &x:a){
	    cin>>x;
	}
	
	sort(a.begin(),a.end());
	
	vector<int>dp(n);
	dp[n-1]=1;
	
	for(int i = n-2 ; i>=0 ; --i ){
	    int maxi = 0;
	    
	    for(int j = i+1; j < n ; ++j){
	    
	        if(a[i]%a[j]==0 or a[j]%a[i]==0){
	    
	            maxi = max(maxi,dp[j]);
	    
	        }
	    
	        dp[i]=1+maxi;
	    }
	    
	}
	
	cout<<*max_element(dp.begin(),dp.end());
	
	
	return 0;
}