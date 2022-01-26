
class Solution {
  public:
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        // sort(arr,arr+n);
        int h=0;
        for(int i = 0 ; i < n ; ++i ){
            h+=arr[i];
        }
        cout<<h;
        int l = 0;
        int mid;
        while(l<h){
            mid =  (l+h)/2;
            int countdays=0,wt=0,maxwt = 0;
            for(int i = 0 ; i < n ; ++ i ){
                if(wt+arr[i]<=mid){
                    wt+=arr[i];
                }else{
                    wt=arr[i];
                    countdays++;
                    // cout<<i<<" ";
                }
                maxwt=max(maxwt,wt);
                // cout<<maxwt<<" ";
            }
            
            if(wt!=0){
                countdays++;
                // cout<<"hello";
            }
            cout<<countdays<<" "<<d<<" "<<mid<<" "<<maxwt;
            cout<<endl;
            if(countdays == d and maxwt==mid){
                // cout<<maxwt<<" ";
                return mid;
            }
            else if(d>countdays or (d==countdays and mid>maxwt)){
                h=mid-1;
            }else{
               l=mid+1; 
            }
        }
        
    }
};