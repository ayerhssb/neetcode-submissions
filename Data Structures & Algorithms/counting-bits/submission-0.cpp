class Solution {
public:
    int countsetbit(int n){
        int cnt=0;
        while(n){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            ans.push_back(countsetbit(i));
        } 
        return ans;
    }
};
