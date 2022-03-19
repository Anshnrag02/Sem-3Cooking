class Solution {
    int n;
    int l,b;
public:
    
    bool checkzero(vector<vector<int>>&a){
        for(auto x:a){
            for(auto y:x){
                if(y==1)
                    return false;
            }
        }
        return true; 
    }
    
    void flipbits(vector<vector<int>>&a,int f){
        int i = f/a[0].size();
        int j = f%a[0].size();
        a[i][j]=!a[i][j];
        if(i>0)
            a[i-1][j]=!a[i-1][j];
        if(i<l-1)
            a[i+1][j]=!a[i+1][j];
        if(j>0)
            a[i][j-1]=!a[i][j-1];
        if(j<b-1)
            a[i][j+1]=!a[i][j+1];
        
    }
    
    int solver(vector<vector<int>>a,int f){
        if(checkzero(a))
            return 0;
        
        if(f==n)
            return INT_MAX;
        
        int b = solver(a,f+1);
        flipbits(a,f);
        int c = solver(a,f+1);
        
        if(b == INT_MAX  and c==INT_MAX)
            return INT_MAX;
        if(b==INT_MAX)
            return 1+c;
        if(c==INT_MAX)
            return b;
        return min(b,1+c);
    }
    
    
    int minFlips(vector<vector<int>>& mat) {
        n = (mat.size())*(mat[0].size());
        l =mat.size();
        b=mat[0].size();
        // vector<vector<int>>a(mat.size(),vector<int>(mat[0].size()));
        // for(int i = 0 ; i < mat.size() ; ++i){
        //     for(int j = 0 ; j < mat[0].size(); ++j)
        //         a[i][j]=mat[i][j];
        // }
        int f=solver(mat,0);
        if(f==INT_MAX) 
            return -1;
        return f;
    }
};