class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.length();

        if(n == 0) return 0;

        int max_ = 1;
        for(int i=0; i<n; i++){
            unordered_set<char> st;
            for(int j=i; j<n; j++){
                if(st.find(s[j]) != st.end()) break;
                st.insert(s[j]);
                max_ = max(max_, j-i+1);
            }
        }

        return max_;
    }
};
