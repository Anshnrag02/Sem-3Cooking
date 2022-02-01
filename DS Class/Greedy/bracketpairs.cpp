#include<bits/stdc++.h>
using namespace std;

int solver(string s){
    int n = s.length();
    vector<int>pos;
    for( int i = 0 ; i < n ; ++i ){

        if(s[i]=='['){
            pos.push_back(i);
        }

    }

    int count =0;
    int p=0;
    int ans = 0 ;
    for(int i = 0 ; i < n ; ++i){
        if(s[i]=='['){
            count++;
            p++;
        }
        else{
            count--;
        }

        if(count<0){
            ans+=pos[p]-i;
            swap(s[i],s[pos[p]]);
            p++;

            count = 1;
        }
    }


    return ans;


}

int main(){
    string s;
    cin>>s;
    cout<<solver(s);

}