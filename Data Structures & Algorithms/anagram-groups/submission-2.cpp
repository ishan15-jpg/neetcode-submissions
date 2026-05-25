class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        size_t n = strs.size();

        unordered_map<string, vector<string>> mp;

        for(const string s : strs){
            vector<int> freq(26, 0);

            for(const char c : s) freq[c - 'a']++;

            string key = to_string(freq[0]);
            for(int i=1; i<26; i++) key += ", " + to_string(freq[i]);

            mp[key].push_back(s);
        }

        vector<vector<string>> answer;

        for(const auto& m : mp) answer.push_back(m.second);

        return answer;
    }
};
