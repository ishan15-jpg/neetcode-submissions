class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        function<bool(string)> isOperator = [&](string op) -> bool {
            if(op == "+" || op == "-" || op == "*" || op == "/") return true;
            return false;
        };

        function<int(int,int,string)> evaluate = [&](int a, int b, string t) -> int {
            if(t == "+") return a + b;
            else if(t == "-") return a - b;
            else if(t == "*") return a * b;
            else return a / b;
        };

        for(const string t : tokens){
            if(isOperator(t)){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int result = evaluate(b,a,t);
                st.push(result);
            }else st.push(stoi(t));
        }

        return st.top();
    }
};
