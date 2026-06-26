class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t n = temperatures.size();

        vector<int> answer(n, 0);
        stack<int> minStack;

        for(int i=n-1; i>=0; --i){
            while(!minStack.empty() && temperatures[i] >= temperatures[minStack.top()]) minStack.pop();

            if(!minStack.empty()) answer[i] = minStack.top() - i;

            minStack.push(i);
        }

        return answer;
    }
};
