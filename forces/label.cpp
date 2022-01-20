#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long int

int bits0(char a){
    switch(a){
        case '0': return 6;
        case '1': return 5;
        case '2': return 5;
        case '3': return 4;
        case '4': return 5;
        case '5': return 4;
        case '6': return 4;
        case '7': return 3;
        case '8': return 5;
        case '9': return 4;
        case 'A': return 4;
        case 'B': return 3;
        case 'C': return 4;
        case 'D': return 3;
        case 'E': return 3;
        case 'F': return 2;
        case 'G': return 5;//16
        case 'H': return 4;
        case 'I': return 4;
        case 'J': return 3;//
        case 'K': return 4;//30
        case 'L': return 3;
        case 'M': return 3;
        case 'N': return 2;//23
        case 'O': return 4;
        case 'P': return 3;
        case 'Q': return 3;//26
        case 'R': return 2;
        case 'S': return 3;
        case 'T': return 2;//29
        case 'U': return 2;
        case 'V': return 1;//31
        case 'W': return 5;//32
        case 'X': return 4;//33
        case 'Y': return 4;
        case 'Z': return 3;
        case 'a': return 4;
        case 'b': return 3;
        case 'c': return 3;
        case 'd': return 2;
        case 'e': return 4;
        case 'f': return 3;
        case 'g': return 3;
        case 'h': return 2;
        case 'i': return 3;
        case 'j': return 2;
        case 'k': return 2;//46
        case 'l': return 1;//47
        case 'm': return 4;
        case 'n': return 3;
        case 'o': return 3;//30
        case 'p': return 2;
        case 'q': return 3;
        case 'r': return 2;//23
        case 's': return 2;
        case 't': return 1;
        case 'u': return 3;//26
        case 'v': return 2;
        case 'w': return 2;
        case 'x': return 1;//29
        case 'y': return 2;
        case 'z': return 1;//61
        case '-': return 1;
        case '_': return 0; 
    }
}

int32_t main(){
    string s;
    cin>>s;
    int n=0;
    for(int i = 0 ; i < s.length(); i++){
        n+=bits0(s[i]);
    }
    int ans = 1;
    for(int i = 0; i < n ; ++i){
        ans = (ans*3)%MOD;
    }
    cout<<ans;
}