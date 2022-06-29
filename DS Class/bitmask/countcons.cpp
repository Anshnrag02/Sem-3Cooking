int solve(int n) {
    int prev = 0;
    int cnt = 0 ;
    int ans = 0;
    while(n){
        if(prev==1 and n&1==1){
            cnt++;
        }
        else if(prev==0 and n&1==1){
            cnt=1;
            prev=1;
        }
        else{
            prev=0;
            cnt=0;
        }
        n=n>>1;
        ans = max(ans, cnt);
    }
    return ans;
}