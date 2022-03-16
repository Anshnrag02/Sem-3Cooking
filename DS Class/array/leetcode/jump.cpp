class Solution {
public:
    bool canJump(vector<int>& a) {
        if(a.size()==1)
            return true;
       int n = a.size();
        bool flag = 0;
        for(int i = 0 ; i < n-1 ; ++ i){
            if(a[i]==0){
                int f=1;
                int j;
                for(j = i-1 ; j>=0 ; j--){
                    if(a[j]>f){
                        break;
                    }
                    f++;
                }
                if(j==-1){
                    flag=1;
                    break;
                }
            }
        }
        return !flag;
    }
};