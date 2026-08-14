class Solution {
public:
    bool canEat(int num, vector<int>& piles, int h){
        int total=0;
        for(int i=0;i<piles.size();i++){
            total += (piles[i]/num);
            if(piles[i]%num >= 1){
                total+=1;
            }
        }
        return total <=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, ans;
        int r = *max_element(piles.begin(), piles.end());
        while(l<=r){
            int mid = l+(r-l)/2;
            if(canEat(mid, piles, h)){
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
