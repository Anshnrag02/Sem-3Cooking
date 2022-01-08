#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int n ; 
	cin>>n;
	vector<int>a(n+1),b(n+1);
	a[0]=1;
	a[1]=0;
	b[0]=0;
	b[1]=1;
	
	for( int i = 2 ; i<= n ; ++i ){
	    a[i]=a[i-2]+2*b[i-1];
	    b[i]=b[i-2]+a[i-1];
	}
	cout<<a[n];
}