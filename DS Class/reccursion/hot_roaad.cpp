#include <bits/stdc++.h>
using namespace std;

int ans=INT_MAX;
int solver(vector<int>From, vector<int>To,vector<int>Temperature, int N, int M,int S, int T, int D, int maxtemp=INT_MIN){
   cout<<S<<" "<<T<<" "<<D<<" "<<maxtemp<<endl;
   
   if(S==T and D==0){
       return maxtemp;
   }
   
   if(D==0){
       return -1;
   }
   for(int i = 0 ; i < From.size() ; i++ ){
        if(From[i] == S){
            int temp = solver(From,To,Temperature,N,M,To[i],T,D-1,max(maxtemp,Temperature[i]));
            if(temp!=-1){
                ans=min(temp,ans);
            }
        }
   }
   if(ans==INT_MAX){
       return -1;
   }
   else{
       return ans;
   }
}


int main(){
    vector<int>From={1,1};
    vector<int>To={1,2};
    vector<int>temp={50,5};
    cout<<solver(From,To,temp,2,2,1,2,3,INT_MIN);
}
