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
int r;


bool T_T(int m,int rec[],int n[], int p[])
{
    int price = 0 ;
    ifor(0,3)
        price+=max((int)0,((m*rec[i])-n[i]))*p[i]; 
    return price<=r;
}

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
        cin>>r;
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
        int l = 0; 
        int h = 1e15;
        while(h-l>1){
            
            int m = l + (h-l)/2;
            // int price = 0 ;
            // ifor(0,3e+=max((int)0,((m*rec[i])-n[i]))*p[i]; 
            if(T_T(m,rec,n,p))
                l=m;
            else
                h=m-1;
        }
        if(T_T(h,rec,n,p))
            cout<<h;
        else
            cout<<l;
    }

}
