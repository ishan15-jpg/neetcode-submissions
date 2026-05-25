class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.length();

        if(n == 0) return 0;

        unordered_set<char> st;
        int max_ = 1, l = 0;

        for(int r=0; r<n; r++){
            while(l <= r && st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            max_ = max(max_, r-l+1);
        }

        return max_;
    }
};
