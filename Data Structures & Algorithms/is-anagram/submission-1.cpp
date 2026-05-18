class Solution {
public:
    bool isAnagram(string s, string t) {
        size_t ns = s.length(), nt = t.length();

        if(ns == 1 && nt == 1) return s[0] == t[0];
        if(ns != nt) return false;

        vector<int> freq(26,0);

        for(const char c : s) freq[c - 'a']++;

        for(const char c : t){
            if(freq[c - 'a'] == 0) return false;
            freq[c - 'a']--;
        }

        return true;
    }
};
