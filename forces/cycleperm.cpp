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
mt19937                   rng(chrono::steady_clock::now().time_since_epoch().count());int n,c,m;

int32_t main()
{
    fio;
    // ll ttt=-1;
	int t =1;
	cin>>t;
    while(t--)
    {
        int n ; cin>> n ; 
        vector<int>a(n+1);
        map<int,int>m;
        ifor(1,n+1){
            cin>>a[i];
            m[a[i]]=i;
        }
        vi ans;
        for(int i = n ; i>=1 ; --i ){
            if(m[i]==i){
                ans.push_back(0);
            }
            else{
                int shift = m[i];
                ans.push_back(m[i]);
                for(int j = i ; j>0 ; --j){
                    if(m[j]<=shift){
                        m[j]=i+m[j]-shift;
                    }else{
                        m[j]=m[j]-shift;
                    }
                }
                

            }
        }
        for(int i = n-1 ; i>=0 ;--i ){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
