
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
#define kfor(a,b)         for(int k = a ; k < b ; k++)
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


int32_t main()
{
    fio;
	int t =1;
	cin>>t;
    while(t--){
        map<int,int>m;
        int n,k;
        cin>>k>>n;
        vi a(n),b(k+1),c(k+1);
        ifor(0,n){
            cin>>a[i];
            m[a[i]]++;
        }
        int mt=INT_MIN;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i = 1 ; i <=k; ++i){
            if(m[i]%3==0){
                b[i]=m[i]/3;
            }
            else if((m[i]+1)%3==0){
                b[i]=(m[i]+1)/3;
            }
            else{
                b[i]=(m[i]-1)/3;
            }
            c[i]=m[i]-b[i];
            pq.push({c[i],i});
            mt=max(mt,c[i]);
        }
        priority_queue<pii>pq2;
        for(int i = 1 ; i <=k; ++i){
            pq2.push({i,b[i]});
        }
        
        while(!pq.empty() and !pq2.empty()){
            pii x=pq.top();
            pii y=pq2.top();
            if(c[i]-)
        }

    }
}
