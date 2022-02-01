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
#define dfor(a,b)         for(int i = b-1 ; i >= a ; i--)
#define fio               ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
mt19937                   rng(chrono::steady_clock::now().time_since_epoch().count());
int a[1001][2],dp[1001][12009],moves[1009],n;

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

int fun(int i , int k){

    if(i==n)
        return 0; 
    if(dp[i][k]!=-1)
        return dp[i][k];
    if(k>=a[i][0])
        return dp[i][k] = max(a[i][1]+fun(i+1,k-a[i][0]),fun(i+1,k));
    return dp[i][k] = fun(i+1,k);
}

int32_t main()
{
    fio;
	int t =1;
	cin>>t;
    // vi moves(1002,INT_MAX);
    for(int i =2; i<=1000;i++){
        moves[i]=INT_MAX;
    }
    moves[1]=0;
    for(int i = 1 ; i < 1002 ; i++ ){
        for(int j =1 ; j <=i ; j++){
                if(i+i/j<1002)
                    moves[i+(i/j)]=min(moves[i+(i/j)],1+moves[i]);
        }
    }
    while(t--)
    {
		int k;
        cin>>n>>k;
        // vector<vi> a(n, vi(2));
        for(int i  = 0 ; i < n ; ++i){
            cin>>a[i][0];
            a[i][0]=moves[a[i][0]];
            // cout<<a[i][0]<<endl;
        }
        for(int i = 0 ; i  < n ; ++i ){
            cin>>a[i][1];
        }
        // for(int i = 0 ; i <n ; ++i ){
        //     for(int j = k ; j>=0 ; --j){
        //         if(j>=a[i][0])
        //             dp[j]=max(dp[j], dp[j-a[i][0]]+a[i][1]);
        //     }
        // }
        k=min(k,12000ll);
        for(int i = 0 ; i <n ; ++i){
            for(int j = 0 ; j<=k; j++){
                dp[i][j]=-1;
            }
        }
        int ans = fun(0,k);
        cout<<ans<<endl;

        // for(int i = 0 ; i <=k ; ++i){
        //     cout<<dp[i]<<endl;
        // }

        // cout<<dp[k]<<endl;

    }
    
}
