class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adjList;
        for(const string word : words)
            for(const char c : word)
                adjList[c];
        for(int i=0; i<words.size()-1; ++i){
            string w1 = words[i], w2 = words[i+1];
            int minLen = min(w1.length(),w2.length());
            if(w1.length() > w2.length() && w1.substr(0,minLen) == w2.substr(0,minLen)) return "";
            for(int j=0; j<minLen; ++j)
                if(w1[j] != w2[j]){
                    adjList[w1[j]].insert(w2[j]);
                    break;
                }
        }
        vector<int> state(26,0);
        string answer = "";
        function<bool(char)> dfs = [&](char c) -> bool {
            if(state[c-'a']) return state[c-'a'] == 1 ? true : false;
            state[c-'a'] = 1;
            for(const char neigh : adjList[c])
                if(dfs(neigh)) return true;
            answer += c;
            state[c-'a'] = 2;
            return false;
        };
        for(const auto &it : adjList){
            if(dfs(it.first)) return "";
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
