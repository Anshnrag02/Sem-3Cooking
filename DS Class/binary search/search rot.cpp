class Solution {
public:
    int search(vector<int>& a, int target) {
        int l = 0 ; 
        int r = a.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if (a[mid] == target)
                return mid;
            if(a[mid]>a[r]){
                if(target<a[mid] and target>=a[l])
                    r=mid-1;
                else
                    l=mid+1;
            }
            else{
                if(target<=a[r] and target>a[mid])
                    l=mid+1;
                else
                    r = mid-1;
            }
        }
        if(a[l]==target)
            return l;
        return -1;
    }
};