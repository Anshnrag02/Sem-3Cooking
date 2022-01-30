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

// void solver( vector<int>&count_cap, vector<int>&v, int x, int i ){
	
// }

int solve(int i, vector<int>&a){
	int l=i,r=i;
	while(l>0){
		if(a[l]>=a[l-1]){
			l--;
		}else{
			break;
		}
	}
	while(r<a.size()-1){
		if(a[r]>=a[r+1]){
			r++;
		}else{
			break;
		}
	}
	return r-l+1;
}


int32_t main()
{
    fio;
	int t =1;
	// cin>>t;
    while(t--)
    {
		int n; cin>>n;
        vi a(n),c(n,0);
        vi left(n+1,-1),right(n+1,-1);

        for(int i = 0 ; i < n ; ++i){
            cin>>a[i];
            if(left[a[i]]==-1){
                left[a[i]]=i;
            }
        }
        for(int i = n-1 ; i>=0 ; i--){
            if(right[a[i]]==-1){
                right[a[i]]=i;
            }
        }
        vector<vi>ranges;
        for(int i = 0; i<=n ; ++i){
            if(left[i]!=-1){
                if(left[i]!=right[i]){

                    ranges.push_back({});

                }
            }
        }
    }
}
