#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define int long long int
#define s second
#define pb push_back
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int end = (b), i = (a); i <= end; ++i)
#define ROF(i, a, b) for (int end = (b), i = (a); i >= end; --i)
#define fast1 ios_base::sync_with_stdio(false)
#define fast2 cin.tie(0)
#define vll vector<ll>
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define mll map<ll,vll>
#define mii map<int,int>
#define mss map<string,string>
#define DRI(X) int (X); cin>>X
#define DRII(X, Y) int X, Y; cin>>X>>Y
#define DRIII(X, Y, Z) int X, Y, Z; cin>>X>>Y>>Z
const ll mod = 1000000007;
// long long get(long long x)
// {
//  return x*(x-1)/2;
// }
// int digits(int n){
//     int count = 0;
//     while(n!=0)  
//    {  
//        n=n/10;  
//        count++;  
//    }  
// return count;
// }

// bool arraySortedOrNot(int arr[], ll n)
// {
//     // Array has one or no element
//     if (n == 0 || n == 1)
//         return true;
 
//     for (int i = 1; i < n; i++)
 
//         // Unsorted pair found
//         if (arr[i - 1] > arr[i])
//             return false;
 
//     // No unsorted pair found
//     return true;
// }

// void rev(int arr[],int i,int j){
//     while(i<=j){
//         swap(arr[i++],arr[j--]);
//     }
// }
// bool isPerfectSquare(long double x)
// {
//     // Find floating point value of
//     // square root of x.
//     if (x >= 0) {
 
//         long long sr = sqrt(x);
         
//         // if product of square root
//         //is equal, then
//         // return T/F
//         return (sr * sr == x);
//     }
//     // else return false if n<0
//     return false;
// }
// ll N = 32768;
// bool isPalindrome(string str)
// {
//     int l = 0;
//     int h = str.size() - 1;
 
//     // Keep comparing characters while they are same
//     while (h > l)
//     {
//         if (str[l++] != str[h--])
//         {
            
//             return false;
//         }
//     }
//     return true;
// }
// int LcmOfArray(vector<int> arr, int idx){
//     // lcm(a,b) = (a*b/gcd(a,b))
//     if (idx == arr.size()-1){
//         return arr[idx];
//     }
//     int a = arr[idx];
//     int b = LcmOfArray(arr, idx+1);
//     return (a*b/__gcd(a,b)); // __gcd(a,b) is inbuilt library function
// }
 
 
int32_t main() {
    fast1;
    fast2;
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vi a(n);
        for(auto &x:a){
            cin>>x;
            x=__builtin_ffs(x)-1;
        }
        int r=max(*min_element(a.begin(),a.end())-1,0);
        for(auto x:a) r+=(x>0);
        cout<<r<<endl;


    }
    return 0; 
}