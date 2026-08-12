typedef long long ll;

class Solution {
public:
    ll square(int n){
        return 1LL*n*n;
    }
    int mySqrt(int x) {
        if(x==0||x==1){return x;}
        int l=1, r=x/2, ans=1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(square(mid)==x){return mid;}
            else if(square(mid)<x){ans=mid; l=mid+1;}
            else{r=mid-1;}
        }
        return ans;
    }
};