#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; 
    cin>>s;
    bool flag = 1;
    int odd_count=0;
    char odd_letter='1';
    map<char,int>m;
    int n = s.length();
    for(int  i = 0 ; i < n ; i++){
        m[s[i]]++;
    }
    for( auto [k,v] : m ){
        if(v&1){
            if(odd_count == 0){
                odd_count++;
                odd_letter=k;
            }
            else{
                flag=false;
            }
        }
    }

    if(flag==true){

        for(char i = 'A'; i<='Z'; i++){
            if(i!=odd_letter){
                for(int j = 0; j<m[i]/2; j++ ){
                    cout<<i;
                }
            }
        }
        for(int j = 0; j<m[odd_letter]; j++ ){
            cout<<odd_letter;
        }
        for(char i = 'Z'; i>='A'; i--){
            if(i!=odd_letter){
                for(int j = 0; j<m[i]/2; j++ ){
                    cout<<i;
                }
            }
        }
            

    }else{
        cout<<"NO SOLUTION";
    }
}