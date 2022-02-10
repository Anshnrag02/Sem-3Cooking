class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0 ; 
        while(i<n){
            //3 cases which do not require change
            //number less than 0 this means a correct option will surely exist in range of 1...n-1
            //number greater than a.length means same as above
            // if the number is in the range then it must be at the correct spot in exactorder 1,2,3,4,..n-1
            if(nums[i]<=0 || nums[i]>n || nums[i]==nums[nums[i]-1]){
                i++;
            }
            else{
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        i = 0 ; 
        // validating the result 
        while(i<n and nums[i]==i+1)
            i++;
        return i+1;
        
        
        
    }
};