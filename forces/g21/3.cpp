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
        int n,x,m,f;
        cin>>n>>m;
        vector<pii> a,b;
        ifor(0,n){
            cin>>x;
            f=0;
            if(x%m==0){
                while(x%m==0){
                    x/=m;
                    f++;    
                    // cout<<f<<x<<endl;
                }
                if(i>0 and a[a.size()-1].first==x){
                    a[a.size()-1].second+=pow(m,f);
                }
                else
                    a.pb({x, pow(m,f)});
            }
            else{
                if(i>0 and a[a.size()-1].first==x){
                    a[a.size()-1].second+=pow(m,f);
                }
                else
                    a.pb({x,1});
            }
            
        }
        int k; cin>>k;
        ifor(0,k){
            cin>>x;
            f=0;
            if(x%m==0){
                while(x%m==0){
                    x/=m;
                    f++;    
                }
                if(i>0 and b[b.size()-1].first==x)
                    b[b.size()-1].second+=pow(m,f);
                else
                    b.pb({x, pow(m,f)});
            }
            else{
                if(i>0 and b[b.size()-1].first==x)
                    b[b.size()-1].second+=pow(m,f);
                else
                    b.pb({x,1});
            }
            
        }
        bool flag=0;
        // ifor(0,a.size()){
        //     cout<<a[i].first<<" "<<a[i].second<<endl;
        // }
        // ifor(0,b.size()){
        //     cout<<b[i].first<<" "<<b[i].second<<endl;
        // }
        if(a.size()!=b.size()){
            flag=1;
        }
        else {
            for(int i = 0 ; i < a.size() ; ++i){
                if(a[i]!=b[i]){
                    flag=1;
                    break;
                }
            }
        }
 
        if(flag)cout<<"NO";
        else cout<<"YES";

        cout<<endl;
    }
}