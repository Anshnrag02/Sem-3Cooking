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
#define mod               998244353
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
// bool f(int mh,int md, int health , int damage){
//     // cout<<"hello";
//     int heroded = (health/md);
//     int monstded = (mh/damage);
//     if(heroded>monstded)
//         return 1;
//     return 0;
// }

int a[1200];

int32_t main()
{
    fio;
    // ll ttt=-1;
	int t =1;
    a[0]=1;
    for(int i = 2 ; i < 1001 ; i+=2){
        a[i]=i;
        // a[i]%=mod;
        a[i]*=i;
        // a[i]%=mod;
        a[i]*=a[i-2];
        a[i]=a[i]/4;
        a[i]%=mod;
    }

	cin>>t;
    while(t--)
    {
        int n; 
        cin>>n;
        bool flag = true;

        vi a(n);
        for(auto &x : a){
            cin>>x;
        }
        if(n==1){
            if(a[0]!=1){
                flag = 0 ;
            }
        }else{
            bool check1=0;
            int cnt =0;
            for(int i = 0 ; i < n ; ++i){
                if(i<n-1 and (a[i+1]-a[i]>1 or (a[i]>a[i+1] and a[i+1]!=1))){
                    flag=0;
                    break;
                }
                if(a[i]==1){
                    check1=1;
                    cnt++;
                }
            }
            if(!check1 or cnt>1){
                flag = 0;
            }
        }
        

        
        flag? cout<<"yes":cout<<"no";
        cout<<endl;
    }
}
