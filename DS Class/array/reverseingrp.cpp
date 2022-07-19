
class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& a, int n, int k){
        // code here
        int i = 0;
        while(i<n){
            int start=i;
            int last = min(i+k-1,n-1);
            while(start<last){
                swap(a[start++],a[last--]);
            }
            i+=k;
        }
    }
};