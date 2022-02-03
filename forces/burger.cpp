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
	// cin>>t;
    while(t--)
    {
        string s;cin>>s;
        int rec[3]={0,0,0},n[3]={0,0,0},p[3]={0,0,0};
        ifor(0,3) cin>>n[i];
        ifor(0,3) cin>>p[i];
        int r; cin>>r;
        ifor(0,s.length()){
            if(s[i]=='B')
                rec[0]++;
            else if (s[i]=='S')
            {
                rec[1]++;
            }
            else{
                rec[2]++;
            }
        }
        int count=0;
        while(rec[0]<=n[0] and rec[1]<=n[1] and rec[2]<=n[2]){
            count++;
            for(int i = 0 ; i < 3 ;++i){
                n[i]-=rec[i];
            }
        }
        int costburger = 0 ;
        for(int i = 0 ; i < 3 ; ++i){
            costburger+=rec[i]*p[i];
        }
        int req[3]={0,0,0};
        while((n[0]>0 or n[1]>0 or n[2]>0)){
            
            int cost = 0;
            ifor(0,3)
            {
                if(n[i]>=rec[i]){
                    n[i]-=rec[i];
                }
                else{
                    cost+=p[i]*(rec[i]-n[i]);
                    n[i]=0;
                }
            }
            if(cost>r){
                break;
            }else{
                r-=cost;
                count++;
            }
        }
        count+=((r/costburger));
        cout<<count;
    }

}
