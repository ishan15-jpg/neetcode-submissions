class Solution {
public:
    bool isValid(string s) {
        size_t n = s.length();

        if(n == 1) return false;

        stack<char> st;

        for(const char c : s){
            if(c == ')'){
                if(!st.empty() && st.top() == '(') st.pop();
                else return false;
            }else if(c == '}'){
                if(!st.empty() && st.top() == '{') st.pop();
                else return false;
            }else if(c == ']'){
                if(!st.empty() && st.top() == '[') st.pop();
                else return false;
            }else st.push(c);
        }

        return st.empty();
    }
};
