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
		int n; cin>>n;
        vi a(n),b(n);
        for(auto &x:a){
            cin>>x;
        }
        
        for(auto &x:b){
            cin>>x;
        }
        bool flag = true;
        for(int i = 0 ; i < n-1 ; ++i){
            if((a[i]-a[i+1])*(b[i]-b[i+1])<0){
                flag = 0 ;
                break;
            }
        }

        if(!flag){
            cout<<-1<<endl;
        }
        else{
            int moves1 = 0;
            vector<pair<int,int>>ans1;        
            int i, j;
            bool swapped;
            for (i = 0; i < n-1; i++)
            {
                swapped = false;
                for (j = 0; j < n-i-1; j++)
                {
                    if (a[j] > a[j+1])
                    {
                        swap(a[j], a[j+1]);
                        moves1++;
                        ans1.pb({j,j+1});
                        swapped = true;
                    }
                }
                if (swapped == false)
                    break;
            }
            int moves2 = 0;
            vector<pair<int,int>>ans2;        
            for (i = 0; i < n-1; i++)
            {
                swapped = false;
                for (j = 0; j < n-i-1; j++)
                {
                    if (b[j] > b[j+1])
                    {
                        swap(b[j], b[j+1]);
                        moves2++;
                        ans2.pb({j,j+1});
                        swapped = true;
                    }
                }
                if (swapped == false)
                    break;
            }
            if(moves1>moves2){
                cout<<moves1<<endl;
                for(auto x : ans1){
                    cout<<x.first+1<<" "<<x.second+1<<endl;
                }
            }
            else{
                cout<<moves2<<endl;
                for(auto x : ans2){
                    cout<<x.first+1<<" "<<x.second+1<<endl;
                }
            }


            
        }

    }
}
