class Solution {
   public:
    string addBinary(string a, string b) {
        int l = a.size() - 1, r = b.size() - 1;
        string ans, carry = "0";
        while (l >= 0 && r >= 0) {
            if ((b[r] == '0' && a[l] == '1') || (a[l] == '0' && b[r] == '1')) {
                if (carry == "1") {
                    ans += "0";
                    carry = "1";
                } else {
                    ans += "1";
                    carry = "0";
                }
            } else if (b[r] == '0' && a[l] == '0') {
                if (carry == "1") {
                    ans += "1";
                    carry = "0";
                } else {
                    ans += "0";
                }
            } else {
                if(carry=="1"){
                    ans += "1";
                }
                else{
                    ans+="0";
                }
                carry = "1";
            }
            l--;
            r--;
        }

        while (l >= 0) {
            if (carry == "1") {
                if (a[l] == '1') {
                    ans += "0";
                    carry = "1";
                }
                else{
                    ans+="1"; carry="0";
                }
            } else {
                ans += a[l];
            }
            l--;
        }
        while (r >= 0) {
            if (carry == "1") {
                if (b[r] == '1') {
                    ans += "0";
                    carry = "1";
                }
                else{
                    ans+="1";
                    carry="0";
                }
            } else {
                ans += b[r];
            }
            r--;
        }
        if(carry=="1"){ans+="1";}
        reverse(ans.begin(), ans.end());
        return ans;
    }
};