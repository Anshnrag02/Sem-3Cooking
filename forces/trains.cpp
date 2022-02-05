//GODLEON'S CODE
#include<bits/stdc++.h>
// #include <boost/math/common_factor.hpp>
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

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

int32_t main()
{
    fio;
	int t =1;
	// cin>>t;
    while(t--)
    {
		int a,b;
        cin>>a>>b;
        int n = a*b/gcd(a,b);
        int masha=0,dasha=0;
        int cb =1, ca=1;
        int  i = 1;
        for(; i <= n ;){
            // cout<<i<<endl;
            if(abs(a*ca-i)<(b*cb-i)){
                dasha+=(a*ca-i)+1;
                i=(a*ca)+1;
                ca++;
                
            }
            else if ((a*ca-i)>(b*cb-i)){
                masha+=(b*cb-i)+1;
                i=b*cb+1;cb++;
                
            }
            else {
                if(a>b){
                    dasha+=(a*ca-i)+1;
                } else {
                    masha+=(b*cb-i)+1;
                }
                break;
            }
        }

        // cout<<dasha<<masha;


        (masha>dasha)?cout<<"Masha":(masha==dasha)?cout<<"Equal":cout<<"Dasha";
    }
}
