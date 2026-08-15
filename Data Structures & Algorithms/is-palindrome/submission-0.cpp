class Solution {
public:
    std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return str;
}
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;
        s = toLower(s);
        while(l<=r){
            if(!isalnum(s[r])){r--;}
            else if(!isalnum(s[l])){l++;}
            else if(s[l]!=s[r]){return false;}
            else{
                r--;l++;
            }
        }
        return true;
    }
};
