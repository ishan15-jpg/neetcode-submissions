class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t n = temperatures.size();

        vector<int> answer(n, 0);

        for(int i=0; i<n; i++){
            int j = i+1;
            while(j < n && temperatures[i] >= temperatures[j]) ++j;
            if(j < n) answer[i] = j-i;
        }

        return answer;
    }
};
