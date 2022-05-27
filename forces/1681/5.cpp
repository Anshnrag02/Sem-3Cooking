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

int countDigit(long long n)
{
   if(n == 0)
     return 1;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

int mex(int n)
{
    int largest = 0;
    // int smallest = 9;
 
    while (n) {
        int r = n % 10;
 
        // Find the largest digit
        largest = max(r, largest);
 
        // Find the smallest digit
        // smallest = min(r, smallest);
 
        n = n / 10;
    }
    return largest;
}
// int dp[1e18+1];

int solver(int n,int l){
    if(countDigit(n)==l){
        return 0;
    }

    

    int temp = n;
    int ans = INT_MAX;
    unordered_set<int>s;
    while(temp){
        s.insert(temp%10);
        temp/=10;
    }
    for(auto f:s){
        if(f>1){
            ans = min(ans,1+solver(n*f,l));
        }
    }

    return ans;
}


int32_t main()
{
    fio;
	int t =1;
	// cin>>t;

    while(t--)
    {
		int n; cin>>n;
        int x; cin>>x;
        queue<int>q;
        map<int,int>m;
        q.push(x);
        m[x]=0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            string s = to_string(temp);
            if(s.length()==n){
                cout<<m[temp]<<endl;
                return 0;
            }
            for(auto f:s){
                if(f>'1'){
                    int w = temp*(f-'0');
                    if(!m.count(w)){
                        q.push(w);
                        m[w]=m[temp]+1;
                    }
                }
                
            }

        }
        cout<<-1<<endl;
    }
}