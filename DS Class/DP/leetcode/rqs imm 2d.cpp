class NumMatrix {
public:
    int a[1000][1000];
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m =  matrix[0].size();
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                a[i][j]=matrix[i][j];
                if(j>0)
                    a[i][j]+=a[i][j-1];
            }
        }
        for(int j = 0 ; j < m ; ++j){
            for(int i = 0 ; i < n ; ++i){
                if(i>0)
                    a[i][j]+=a[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = a[row2][col2];
        if(row1>0){
            sum-=a[row1-1][col2];
        }
        if(col1>0){
            sum-=a[row2][col1-1];
        }
        if(row1>0 and col1>0){
            sum+=a[row1-1][col1-1];       
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */