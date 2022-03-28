//ANXH'S CODE
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
#define vvi               vector<vi>
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

int n,c,m;

bool f(int mh,int md, int health , int damage){
    if(damage*health>md*mh)
        return 1;
    return 0;
}

// bool f(int mh,int md, int health , int damage){
//     // cout<<"hello";
//     int heroded = (health/md);
//     int monstded = (mh/damage);
//     if(heroded>monstded)
//         return 1;
//     return 0;
// }



int32_t main()
{
    fio;
    // ll ttt=-1;
	int t =1;
	cin>>t;
    while(t--)
    {
        int d;
        cin>>n>>d;
        vector<int>a(n+1);
        a[0]=0;
        int min_pos,mu=1e9;
        for(int i = 1 ; i <=n ; ++i){
            cin>>a[i];
            if(a[i]-a[i-1]-1<mu){
                mu=a[i]-a[i-1]-1;
                min_pos=i;
            }
        }
        vector<int>b;
        for(int i = 1  ; i <=n; ++i ){
            if(i!=min_pos){
                b.pb(a[i]);
            }
        }
        // mu = max(b[0]-1,mu);
        for(int i = 0 ; i < b.size()-1; ++i){
            mu = max((b[i+1]-b[i]-1)/2,mu);
        }
        mu = max(mu,d-b.back()-1);
        b[min_pos-2]=a[min_pos];
        for(int i = 0 ; i < b.size()-1; ++i){
            mu = max((b[i+1]-b[i]-1)/2,mu);
        }
        mu = max(mu,d-b.back()-1);

        cout<<mu<<endl;
    }
}
