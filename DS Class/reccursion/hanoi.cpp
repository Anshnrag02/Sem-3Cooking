#include<bits/stdc++.h>
using namespace std;

void toh(int n, char from, char via , char to){
    if(n==0){
        return;
    }

    toh(n-1,from,to,via);
    cout<<from<<" to "<<to<<endl;
    toh(n-1,via,from,to);
}

int main(){
    int n=3;
    toh(n,'A','B','C');
}