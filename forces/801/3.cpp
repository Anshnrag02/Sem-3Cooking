//GODLEON'S CODE
#include<bits/stdc++.h>
using namespace std;

#define ff                first
#define ss                second
#define int        	  long long
#define ll                long long
#define ddouble           long double  
#define pb 		  push_back
#define mp 		  make_pair
#define pii               pair<int , int>
#define vi                vector<int>
#define vvi                vector<vi>
#define mii               map<int,int>
#define gsort             greater<int>
#define pqb               priority_queue<int>
#define pqs               priority_queue<int , vi , greater<int>>
#define setbits(x)        __builtin_popcountll(x)
#define zrobits(x)        __builtin_ctzll(x)
#define mod               1000000007
#define mod1              mod
#define mod2              1000000009
#define inf               1e18
#define ps(x,y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)    type *arr = new type[n] ;
#define test(t)           int t ; cin >> t ; while(t--)
#define ifor(a,b)         for(int i = a ; i < b ; i++)
#define jfor(a,b)         for(int j = a ; j < b ; j++)
#define dfor(a,b)         for(int i = b-1 ; i >= a ; i--)
#define fio               ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
mt19937                   rng(chrono::steady_clock::now().time_since_epoch().count());


// check odd even : n & 1
// check power of 2 : n & n - 1 == 0
//flip xor
//set or
//unset and
//for -ve no.s mod ( a % mod + mod ) % mod ; 

/*
ll power(ll x, ll y, ll p) 
{ 
	if(x==0 && y==0)
	{
		return 1;
	}
	ll res = 1;	 
	x = x % p;  

	if (x == 0) return 0; 

	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res*x) % p; 
		y = y>>1;
		x = (x*x) % p; 
	} 
	return res; 
} 
*/

int maxp[1001][1001],minp[1001][1001];
vvi a(1001,vi(1001));


int32_t main()
{
    fio
    int t; cin>>t;
    while(t--){
		int n , m ;
		cin>>n>>m;
		int x=0,y=0;
		int mx = INT_MIN;
		
		ifor(0,n){
			jfor(0,m){
				cin>>a[i][j];
			}
		}
		minp[0][0]=maxp[0][0]=a[0][0];
		ifor(1,n){
			maxp[i][0]=minp[i][0]=a[i][0]+minp[i-1][0];
		}
		ifor(1,m){
			maxp[0][i]=minp[0][i]=a[0][i]+minp[0][i-1];
		}

		ifor(1,n){
			jfor(1,m){
				maxp[i][j]=a[i][j]+max(maxp[i-1][j],maxp[i][j-1]);
				minp[i][j]=a[i][j]+min(minp[i-1][j],minp[i][j-1]);				
			}
		}
		if(minp[n-1][m-1]<=0 and maxp[n-1][m-1]>=0 and (n+m)%2!=0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
    }
}
