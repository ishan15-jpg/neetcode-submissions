class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t n = temperatures.size();

        vector<int> answer(n, 0);
        stack<int> minStack;

        for(int i=0; i<n; ++i){
            while(!minStack.empty() && temperatures[i] > temperatures[minStack.top()]){
                answer[minStack.top()] = i - minStack.top();
                minStack.pop();
            }
            minStack.push(i);
        }

        return answer;
    }
};
