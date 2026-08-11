class Solution {
public:
    string binary(uint32_t n){
        string ans="";
        while(n){
            ans+= to_string(n%2);
            n=n/2;
        }
        reverse(ans.begin(), ans.end());
        int i=32-ans.size();
        string str;
        while(i){str+="0";i--;}
        ans = str+ans;
        return ans;
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        string bin = binary(n);
        // cout<<"n: "<<n<<'\n';
        // cout<<str<<'\n';
        cout<<bin<<"\n";
        // ans = stoi(bin);
        for(int i=0;i<32;i++){
            uint32_t num = (bin[i]=='0')?0:1;
            ans+= (num* pow(2, i));
        }
        return ans;
    }
};
