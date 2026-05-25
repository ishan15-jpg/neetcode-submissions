class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.length();

        if(n == 0) return 0;

        unordered_map<char,int> mp;
        int max_ = 1, l = 0;

        for(int r=0; r<n; r++){
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l) l = mp[s[r]]+1;
            mp[s[r]] = r;
            max_ = max(max_, r-l+1);
        }

        return max_;
    }
};
