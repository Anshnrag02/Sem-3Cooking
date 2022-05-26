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
	cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.length();
        int cost = 0;
        vector<bool>a;
        vector<int>l1(n),l2(n),l3(n),r3(n),r1(n),r2(n);
        for(auto x:s){
            if(x=='0'){
                cost++;
                a.pb(0);
            }
            else{
                a.pb(1);
            }
        }

        l1[0]=a[0];
        l2[0]=cost-!a[0];
        l3[0]=max(l2[0],l1[0]);
        int lmin=l3[0],lminidx=0;
        for(int i = 1 ; i<n ;++i){
            l1[i]=l1[i-1]+a[i];
            if(a[i]==0 and l2[i-1]>0)
                l2[i]=l2[i-1]-1;
            else{
                l2[i]=l2[i-1];
            }
            l3[i]=max(l1[i],l2[i]);
            if(l3[i]<lmin){
                lmin=l3[i];
                lminidx=i;
            }
        }
        
        r1[n-1]=a[n-1];
        r2[n-1]=cost-!a[n-1];
        r3[n-1]=max(r2[n-1],r1[n-1]);
        int rmin=r3[n-1],rminidx=n-1;
        for(int i = n-2 ; i>=0 ;--i){
            r1[i]=r1[i+1]+a[i];
            if(a[i]==0 and r2[i+1]>0)
                r2[i]=r2[i+1]-1;
            else{
                r2[i]=r2[i+1];
            }
            r3[i]=max(r1[i],r2[i]);
            if(r3[i]<rmin){
                rmin=r3[i];
                rminidx=i;
            }
        }
        // cout<<lminidx<<lmin<<rminidx<<rmin<<l2[1]<<l1[1]<<l3[1];
        if(lminidx<rminidx)
            cout<<min({cost,cost-(cost-lmin)-(cost-rmin)})<<endl;
        else if(lminidx>rminidx){
            cout<<min({cost,cost-(cost-lmin),cost-(cost-rmin)})<<endl;
        }
        else{
            cout<<min
        }


    }

}
