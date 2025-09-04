class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        if(a.length() < b.length())
            swap(a, b);
        
        int alen = a.length(), blen = b.length();
        while(b.length() < alen) 
            b += '0';

        int carry = 0;
        string ret = "";
        for(int i = 0; i < alen; ++i) {
            int num = (a[i] - '0') + (b[i] - '0') + carry;
            ret += to_string(num & 1);
            carry = num & 2 ? 1: 0;

            // if(a[i] == '1' && b[i] == '1') {
            //     ret += carry == 1 ? '1' : '0';
            //     carry = 1;
            // }else if(a[i] == '0' && b[i] == '0') {
            //     ret += carry == 1 ? '1' : '0';
            //     carry = 0;
            // } else {
            //     ret += carry == 1? '0' : '1';
            //     carry = carry == 1? 1 : 0;
            // }
        }

        if (carry)
            ret += '1';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};