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

int a[1001][1001];
int d[1001][1001];
bool vis[1001][1001];
int n,m,k;
pair<int,int>s;
string ans = "";

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

bool lesgo(int x, int y, int moves = 0){
    if(moves==k and s=={x,y}) return 1;

    


}

vector<pii> af(int x , int y){
    vector<pii> p;
    if(x>0 and a[x-1][y]!='*'){
        p.pb({x-1,y});
    }
    if(y>0 and a[x][y-1]!='*'){
        p.pb({x,y-1});
    }
    if(x<n-1 and a[x+1][y]!='*'){
        p.pb({x+1,y});
    }
    if(x>0 and a[x][y+1]!='*'){
        p.pb({x,y+1});
    }
    return p;
}

void solve(){
    if(k%2==1){
        cout<<"IMPOSSIBLE";
        return;
    }
    if(!lesgo(s.first,s.second))
        cout<<"IMPOSSIBLE";
    else
        cout<<ans;
}

void sd(){

    queue<pair<int,int>>q;
    q.push(s);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        vector<pii>adj = af(x,y);
        for(auto l:adj){
            if(!vis[l.first][l.second]){
                vis[l.first][l.second]=1;
                q.push(l);
                d[l.first][l.second]=d[x][y];
            }
        }
    }
}


int32_t main()
{
    fio;
	int t =1;
    while(t--)
    {
        cin>>n>>m>>k;
        ifor(0,n){
            for (int j = 0; j < m; j++){
                cin>>a[i][j];
                d[i][j]=INT_MAX;
                vis[i][j]=0;
                if(a[i][j]=='X'){
                    s={i,j};
                    d[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        sd();
        solve();    
    }
}
