#include<bits/stdc++.h>
using namespace std;


typedef long double LD;
typedef long long LL;
 
using namespace std;
 
#define sz(A) (A).size()
#define mp make_pair
#define pb push_back
 
int n, m;
 
LL power(int num, int deg) {
    if (!deg)
        return 1;
 
    if (deg % 2) {
        return (power(num, deg - 1) * num) % m;     
    }
    else {
        LL sqrt_res = power(num, deg / 2);
        return (sqrt_res * sqrt_res) % m;
    }
}
 
int main() {
    cin >> n >> m;
    LL res = power(3, n);
    res--;
    if (res < 0) res += m;
    cout << res << endl;    
    return 0;
}