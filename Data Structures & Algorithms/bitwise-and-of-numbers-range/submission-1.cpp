class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // int ans=1,n=0;
        // string str="";
        // for(int i=31;i>=0;i--){
        //     int bit_and=(left&(1<<i));
        //     for(int j=left+1;j<=right;j++){
        //         bit_and = bit_and & (j&(1<<i));
        //     }
        //     n+=bit_and;
        // }
        // return n;
        int cnt=0;
        while(left!=right){
            left=left>>1;right>>=1;
            cnt++;
        }
        int num = left<<cnt;
        return num;
    }
};