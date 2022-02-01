#include<bits/stdc++.h>
using namespace std;

int floor_div(int a, int b) {
    int d = a / b;


    return d * b == a ? d : d - ((a < 0) ^ (b < 0));
}


int main(){
    int wall,n,m;cin>>wall>>n>>m;

    int min_wall=wall;
    int current_wall=wall;
    int min_n = floor_div(wall,n);
    int min_m = floor_div(wall-n*min_n,m);
    int current_n = min_n;
    int current_m = min_m;
    while(current_n){
        current_wall= wall - n*current_n - m*current_m;
        if(current_wall<min_wall){
            min_wall = current_wall;
            min_m =current_m;
            min_n =current_n;
        }
        current_n--;
        current_m = floor_div(wall-n*current_n,m);
    }

    cout<<min_wall<<" "<<min_n<<" "<<min_m<<endl;
}