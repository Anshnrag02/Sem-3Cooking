class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int dist = hc[0];
        for(int i = 1 ; i < hc.size(); i++){
            dist=max(dist,hc[i]-hc[i-1]);
        }
        int vist= vc[0];
        for(int i = 1 ; i < vc.size(); i++){
            vist=max(vist,vc[i]-vc[i-1]);
        }
        vist=max(vist,w-vc[vc.size()-1]);
        dist=max(dist,h-hc[hc.size()-1]);
        long int temp = (vist);
        temp*=(dist);
        temp%=1000000007;
        return temp;
    }
};