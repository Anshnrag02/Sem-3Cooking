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
int m=(1<<22)-1;
vector<int>dp(1+m,0);

int32_t main()
{
    fio;
    // ll ttt=-1;
	int n; cin>>n;
    
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i];
        dp[m^a[i]]=a[i];
        
    }
    for(int i = m; i>=0 ; --i){
        if(!dp[i]){
            for(int j=0; j<22 ; ++j){
                if(dp[i|(1<<j)]){
                    dp[i]=dp[i|(1<<j)];
                    break;
                }
            }
        }
    }

    for(int i=0 ; i<n ; ++i){
        if(dp[a[i]])
        cout<<dp[a[i]]<<" ";
        else    cout<<"-1 ";
    }


}


// #include <cstdio>
//   int a[1000010],vis[1<<22];
//   int main(){
//       int n,mask = (1<<22)-1;
//       scanf("%d",&n);
//       for(int i = 0;i < n;i++){
//           scanf("%d",&a[i]);
//           vis[mask^a[i]] = a[i];
//       }
//      for(int i = mask;i >= 0;i--){
//          if(vis[i])  continue;
//          for(int j = 0;j < 22;j++){
//              if(vis[i|(1<<j)]){
//                  vis[i] = vis[i|(1<<j)];
//                  break;
//              }
//          }
//      }
//      for(int i = 0;i < n;i++){
//          if(vis[a[i]])   printf("%d ",vis[a[i]]);
//          else    printf("-1 ");
//      }
// }