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
// int l[1000001],a[1000001],r[1000001],p[1000001];

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
int ans = 0;

int m,q,n;
int a[1000001];

bool f(int k){
    int i = 0 ;
    int cnt=0;
    int temp=0;
    while(i<n){
        temp+=q;
        if(i<n and temp<a[i]){
            // cout<<"YES";
            return false;
        }
        while(temp>=a[i] and i<n){
            temp-=a[i];
            ++i;
        }
        cnt++;
    }
    // cout<<cnt<<endl;
    if(cnt<=k)
        return 1;
    return 0;
}

int32_t main()
{
    fio
    cin>>n;
    for(int i = 0 ; i < n ; ++i) cin>>a[i];
    
    cin>>m;
    // vi q(m);
    for(int i = 0 ; i < m ; ++i){   
        cin>>q;
        int l = 0, r =1e9;
        int mid;
        while(l<r){
            mid = (l+r)>>1;
            if(f(mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        // cout<<mid;
        if(f(l)){
            cout<<l;
        }
        else{
            cout<<-1;
        }
        // cout<<f(5);
        cout<<'\n';
    }


}
