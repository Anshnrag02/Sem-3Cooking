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
#define vvi                vector<vector<int>>
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
#define dfor(a,b)         for(int i = b-1 ; i >= a ; i--)
#define fio               ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
mt19937                   rng(chrono::steady_clock::now().time_since_epoch().count());



void solve(){
    int n; int m; cin>>n>>m;
    vvi a(n,vi(m));
    ifor(0,n){
        jfor(0,m){
            cin>>a[i][j];
        }
    }
    vi temp;
    ifor(0,n){
        vi b = a[i];
        sort(b.begin(),b.end());
        jfor(0,m){
            if(a[i][j]!=b[j])
                temp.pb(j);
        }
        if(!temp.empty())
            break;
    }
    if(temp.size()>2){

        cout<<"-1\n";
    }
    else if(temp.size()==0){
        cout<<"1 1\n";
    }
    else{
        ifor(0,n){
            swap(a[i][temp[0]],a[i][temp[1]]);
        }
        ifor(0,n){
            jfor(1,m){
                if(a[i][j]<a[i][j-1])
                {
                    // cout<<"Here fuck"<<i<<"  "<<j<<"\n";
                    cout<<"-1\n";
                    return;
                }
            }
        }
        cout<<temp[0]+1<<" "<<temp[1]+1<<"\n";
    }
}

int32_t main()
{
    fio;
	int t =1;
	cin>>t;

    while(t--)
    {
		solve();
    }
}
