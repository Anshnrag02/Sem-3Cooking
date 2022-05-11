class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int>s;
        int  max_area=0;
        a.push_back(-1);
        int n = a.size();
        for(int i = 0 ; i < n ; ++i){
            while(!s.empty() and a[s.top()]>a[i]){
                int temp = s.top();
                s.pop();
                int area = a[temp]*((s.empty())?i:i-s.top()-1);
                max_area = max(area,max_area);
            }
            
            s.push(i);
            
        }        
        return max_area;
    }
};