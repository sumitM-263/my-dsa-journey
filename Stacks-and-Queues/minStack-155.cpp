#include <bits/stdc++.h>
using namespace std;

// LeetCode 155 - MinStack

class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }
        else{
            int top = st.top().second;
            int x = min(val, top);
            st.push({val, x});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main(){

    MinStack st;
    st.push(2);
    st.push(-1);
    st.push(10);
    st.push(-100);
    st.push(2000);

    cout << st.getMin() << '\n';
    cout << st.top() << '\n';
}