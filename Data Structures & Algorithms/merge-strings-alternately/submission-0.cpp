class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l=0, r=0, flag=1;
        string ans="";
        int w1=word1.size(),w2=word2.size();
        while(l<w1 && r<w2){
            if(flag){ans+=word1[l];flag=0;l++;}
            else{ans+=word2[r];flag=1;r++;}
        }
        while(l<w1){
            ans+=word1[l];l++;
        }
        while(r<w2){
            ans+=word2[r];r++;
        }
        return ans;
    }
};