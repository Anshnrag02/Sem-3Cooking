//Count Binary Strings with No Consecutive 1s 


//DP approach O(n)

#include<bits/stdc++.h>
using namespace std;

int safe(int i , int j , vector<vector<int>> board){
    int n=board.size();
    for (int x = 0;x < i;x++){
		if(board[x][j]!=0)
			return false;
	}
	int x=i;
	int y = j;
	while(x>=0&&y>=0){
		if(board[x][y]!=0)
			return false;
		x--;
		y--;
	}
	x=i;
	y = j;
	while(x>=0&&y<n){
		if(board[x][y]!=0)
			return false;
		x--;
		y++;
	}
	return true;
}

bool NQ(vector<vector<int>> board,int i=0){
    int n =board.size();
    if(i==board.size()){
        for(int p = 0 ; p < n ; p++){
            for(int q = 0 ; q < n ; q++){
                cout<<board[p][q]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        return false;
    }

    for(int j = 0; j<board.size() ; ++j){
        if(safe(i,j,board)){
            board[i][j]=1;
            bool check=NQ(board,i+1);
            if(check){
                return 1;
            }
            board[i][j]=0;
        }
    }
    return false;
}

int main(){
    
    int n; cin>>n;
    vector<vector<int>>board(n,vector<int>(n));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j<n ; ++j){
            board[i][j]=0;
        }
    }
    bool a = NQ(board);
}