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

class Compare
{
public:
    bool operator()(vector<int>a,vector<int>b){
    if(a[1]==b[1])
        return a[0]<b[0];    
    
    return a[1]<b[1];
}
};




int32_t main()
{
    fio;
    // ll ttt=-1;
	int t =1;
	cin>>t;
    while(t--)
    {

        int n , m ; 
        
        cin>>n>>m;
        
        vvi a(m,vi(3));
        
        int _=1;

        for(auto &x : a){
            cin>>x[0]>>x[1];
            x[2]=_;
            ++_;
        }

        sort(a.begin(),a.end());
        priority_queue<vi,vvi,Compare>pq;
        int sum = 0 ; 
        for(int i = 0 ; i < m ; ++i){
            if(pq.size()<2*n){
                pq.push(a[i]);
                sum+=a[i][1];
            }
            else if(pq.top()[1]>=a[i][1]){
                sum-=pq.top()[1];
                pq.pop();
                sum+=a[i][1];
                pq.push(a[i]);
            }
        }
        vvi ans;
        while(pq.size()>0){
            ans.pb(pq.top());
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        int i = 0;
        int j = 2*n-1;
        cout<<sum<<endl;
        while(i<n){
            cout<<ans[i][2]<<" "<<ans[j][2]<<endl;
            i++;
            j--;
        }   
    }
}
