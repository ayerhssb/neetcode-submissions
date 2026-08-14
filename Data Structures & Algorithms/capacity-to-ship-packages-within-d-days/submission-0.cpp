class Solution {
public:
    bool canShip(int num, int days, vector<int>& weights){
        int total=0, d=0;
        for(int i=0;i<weights.size();i++){
            if(total+weights[i] <= num){
                total+= weights[i];
            }
            else{
                d++;
                total=weights[i];
            }
            // if(d>days){return false;}
        }
        if(total<=num){d++;}
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int r=accumulate(weights.begin(), weights.end(),0), l=*max_element(weights.begin(), weights.end()), ans;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(canShip(mid, days, weights)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};