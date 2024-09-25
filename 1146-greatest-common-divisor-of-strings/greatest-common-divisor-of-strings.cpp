class Solution {
  public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.length(), l2 = str2.length();

        string gcd = l1 < l2 ? str1 : str2; // smaller string set to the gcd

        for (int i = min(l1, l2); i > 0; --i) {
            if (isValidGcd(str1, str2, l1, l2, gcd))
                return gcd;

            gcd = gcd.substr(0, i); // reduce the substring
        }

        return "";
    }

    bool isValidGcd(const string str1, const string str2, int l1, int l2, string substr) {
        int len = substr.length();
        if (l1 % len || l2 % len)
            return false;

        for(int i = 0; i < l1; i += len){
            if(str1.substr(i, len) != substr) return false;
        }

        for(int i = 0; i < l2; i+= len){
            if(str2.substr(i, len) != substr) return false;
        }

        return true;
    }
};