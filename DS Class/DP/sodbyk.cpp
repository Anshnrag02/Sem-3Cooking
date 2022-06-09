#include<bits/stdc++.h>
using namespace std;

int n;
string s;


int k(int idx, int last, int cnt);
{
    if(idx==s.length()){
        return cnt;
    }


    int till=last?s[idx]-'0':9;

    for(int i = 0 ; i<= till ; ++i){
        
    }

}


int f(int x){

    n=x;
    s=to_string(n);

    return k(0,1,0);
}

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    cout<<f(b)-f(a-1);
}