class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        size_t n = strs.size();

        unordered_map<string, vector<string>> mp;

        for(const string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }

        vector<vector<string>> answer;

        for(const auto& m : mp){
            answer.push_back(m.second);
        }

        return answer;
    }
};
