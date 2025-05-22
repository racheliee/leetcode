class Solution {
public:
    bool isPalindrome(int x) {
        string original = to_string(x);
        string reversed = original;
        reverse(reversed.begin(), reversed.end());

        return original == reversed;
    }
};