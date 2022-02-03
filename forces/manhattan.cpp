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
void bruh(queue<int>&a,queue<int>&b){
    int f=a.front();
    int g = b.front();
    b.pop();
    a.pop();
    a.push(g);
    a.push(f);

}

int nc2(int n){
    if(n<=1) return 0;
    return (n*(n-1))/2;
}

int32_t main()
{
    fio;
	int t =1;
	// cin>>t;
    while(t--)
    {

        int n;
        cin >>n;
        vector<vi>a(n,vi(2));
        
        for(int i = 0 ; i<n; i++){
            cin>>a[i][0]>>a[i][1];
        }
        
        sort(a.begin(),a.end());
        int count=1;
        int ans = 0 ;
        for(int i = 1 ; i<n ; ++i){

            if(a[i][0]==a[i-1][0]){
                count++;
            }
            else{
                ans+=nc2(count);
                count=1;
            }

        }

        if(count){
            ans+=nc2(count);
        }

        // cout<<ans;

        count =1;

        for(int i = 0 ; i < n ; ++ i){
            swap(a[i][0],a[i][1]);
        }

        sort(a.begin(),a.end());

        for(int i = 1 ; i<n ; ++i){

            if(a[i][0]==a[i-1][0]){
                count++;
            }
            else{
                ans+=(nc2(count));
                count=1;
            }

        }

        if(count){
            ans+=(nc2(count));
        }


        count = 1;

        for(int i = 1 ; i<n ; ++i){

            if(a[i][0]==a[i-1][0] and a[i][1]==a[i-1][1]){
                count++;
            }
            else{
                ans-=(nc2(count));
                count=1;
            }

        }

        if(count){
            ans-=(nc2(count));
        }


        cout<<ans;

    }

}
