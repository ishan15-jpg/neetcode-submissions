class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t n = temperatures.size();

        vector<int> answer(n, 0);
        
        for(int i=n-2; i>=0; --i){
            int j = i+1;
            while(j<n && temperatures[j] <= temperatures[i]){
                if(answer[j] == 0){
                    j = n;
                    break;
                }
                j += answer[j];
            }
            if(j < n) answer[i] = j - i;
        }

        return answer;
    }
};
