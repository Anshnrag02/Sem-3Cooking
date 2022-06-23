// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    int ans = 0 ;
    
    void bfs(int n , int m , int x){
        queue<int>q;
        q.push(x);
        while(!q.empty()){
            
            int f =q.front();
            q.pop();
            if(f>=n and f<=m){
                ans++;
            }
            
            if(f>m or x==0) continue;
            
            
            int ln = f%10;
            
            if(ln==0){
                q.push(10*f + ln+1);
            }
            else if(ln==9){
                q.push(10*f + ln-1);
            }
            else{
                q.push(10*f + ln-1);
                q.push(10*f + ln+1);
            }
            
            
        }
        
    }
    

    int steppingNumbers(int n, int m)
    {
        // Code Here
        ans=0;
        for(int i = 0 ; i <= 9; ++i){
            bfs(n,m,i);
        }
  
        return ans;      
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}

  // } Driver Code Ends