class Solution {
    bool isAlphanumeric(const char i){
        return (65 <= i && i <= 90) || (97 <= i && i <= 122) || (48 <= i && i <= 57);
    }

    char toLower(char i){
        if((97 <= i && i <= 122) || (48 <= i && i <= 57))  return i;
        return (char)(i - 'A' + 97);
    }

public:
    bool isPalindrome(string s) {
        size_t n = s.size();

        int i = 0, j = n-1;

        while(i < j){
            while(i < j && !isAlphanumeric(s[i])) i++;
            while(i < j && !isAlphanumeric(s[j])) j--;
            if(toLower(s[i]) != toLower(s[j])) return false;
            i++; j--;
        }

        return true;
    }
};
