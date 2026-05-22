class MinStack {
    stack<pair<int,int>> st;

public:
    MinStack() {}
    
    void push(int val) {
        if(st.empty() || st.top().second > val){ 
            st.push({val,val});
            return;   
        }
        st.push({val, st.top().second});
    }
    
    void pop(){
        if(!st.empty()) st.pop();
    }
    
    int top(){
        if(!st.empty()) return st.top().first;
    }
    
    int getMin(){
        if(!st.empty()) return st.top().second;
    }
};
