class Solution {
    bool isPalindrome(string s){
        int i = 0, j = s.length()-1;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }

        return true;
    }

public:
    string longestPalindrome(string s) {
        size_t n = s.length();

        if(n == 1) return s;

        int max_ = 0;
        string answer = "";

        for(int i=0; i<n; i++)
        for(int j=0; j<i+1; j++)
        if(s[j] == s[i] && isPalindrome(s.substr(j, i-j+1))){
            if(i-j+1 > max_){
                max_ = i-j+1;
                answer = s.substr(j, i-j+1);
            }
        }

        return answer;
    }
};
