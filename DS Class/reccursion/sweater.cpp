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
int min_rev(string s,unordered_set<char>&us){
    if(s.length()== 0 or s.length()==1){
        return 0;
    }

    // cout<<s<<endl;
    string o1;

    if (s[0]==s[s.size()-1]){
        o1=s.substr(1,s.size()-2);
        cout<<"bsssslue"<<o1<<endl;
        return min_rev(o1,us);
    }

    int a=-1,b=-1;

    if (s[0] != s[s.size()-1]){
        if(us.size()==0){
            us.insert(s[0]);
            o1=s.substr(1);
            cout<<"blue"<<o1<<endl;
            a = min_rev(o1,us);
            us.erase(s[0]);
            us.insert(s[s.size()-1]);
            o1=s.substr(0,s.size()-2);
            cout<<"Yellow"<<o1<<endl;
            b = min_rev(o1,us);
            us.erase(s[s.size()-1]);
        }
        if(us.size()==1){
            if(us.find(s[0])!=us.end()){
                
                o1=s.substr(1);
                cout<<"blek"<<o1<<endl;
                a = min_rev(o1,us);
            }

            if(us.find(s[s.size()-1])!=us.end()){
                o1=s.substr(0,s.size()-2);
                cout<<"tue"<<o1<<endl;    
                b = min_rev(o1,us);
            }
        }
    }

    if(a==-1 and b==-1){
        return -1;
    }
    if(a==-1)
        return b+1;
    if (b==-1)
        return a+1;

    return min(a,b)+1;

}

int32_t main()
{
    fio;
    test(t)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_set<char>m;
        int a=min_rev(s,m);
        cout<<a<<endl;
    }
}
