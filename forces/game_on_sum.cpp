#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define p mod

ll k,two;

ll power(ll x, ll y ) 
{ 
    ll res = 1;
    x = x % p; 
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;  
        x = (x*x) % p; 
    } 
    return res; 
} 
ll modInverse(ll n ) 
{ 
    return power(n, p-2); 
} 
ll dp[2009][2009];
ll f(ll n,ll m)
{
	if(n==0||m==0)
		return 0;
	if(n==m)
		return (k*m)%mod;
	if(dp[n][m]!=-1)
		return dp[n][m];
	ll ans=f(n-1,m);
	ans+=f(n-1,m-1);
	ans%=mod;
	ans*=two;
	ans%=mod;
	return dp[n][m]=ans;
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//   #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//   #endif
    two=modInverse(2);
  ll T,tt=1,n,i,j,m;
  cin>>T;
  while(T--)
  {
  	//cout<<"Case #"<<tt<<": ";
  	//tt++;
  	cin>>n>>m>>k;
  	i=1;
  	while(i<=n)
  	{
  		j=0;
  		while(j<=m)
  		{
  			dp[i][j]=-1;
  			j++;
  		}
  		i++;
  	}
  	cout<<(f(n,m))<<endl;
  }
}   			