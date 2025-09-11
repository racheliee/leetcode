class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.length();

        if(len == 1)
            return "";

        for(int i = 0; i < len/2 + 1; ++i) {
            if(palindrome[i] != 'a' && palindrome[len-i-1] != 'a' && i != (len-i-1)) {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        palindrome[len-1] = 'b';
        return palindrome;
    }
};