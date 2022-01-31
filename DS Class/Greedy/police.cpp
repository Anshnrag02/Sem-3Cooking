#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,count=0;
    cin>>n>>k;
    string s; 
    cin>>s;
    queue<int>t_idx;
    queue<int>p_idx;
    for(int i = 0 ; i<n; ++i){
        if(s[i]=='T'){
            if(p_idx.empty()){
                t_idx.push(i);
            }
            else{
                bool caught=false;
                while(p_idx.size()){
                    if(abs(p_idx.front()-i)<=k){
                        count++;
                        caught=true;
                        p_idx.pop();
                        break;
                    }
                    p_idx.pop();                    
                }

                if(!caught){
                    t_idx.push(i);
                }
            }
        }
        else{
            if(t_idx.empty()){
                p_idx.push(i);
            }
            else{
                bool caught = false;
                while(t_idx.size()){
                    if(abs(t_idx.front()-i)<=k){
                        count++;
                        caught=true;
                        t_idx.pop();
                        break;
                    }
                    t_idx.pop();
                }
                if(!caught){
                    p_idx.push(i);
                }
            }
        }
    }
    cout<<count;
}