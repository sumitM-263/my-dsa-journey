#include <iostream>
using namespace std;
const int N = 1000;

class Stack{

    int arr[N];
    int top;

public:

    Stack(){
        top = -1;
    }


    void push(int x){
        if(top == N-1){
            cout << "Stack is full \n";
            return;
        }

        arr[++top] = x;
        
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack is empty" << '\n';
            return -1;
        }
        
        return arr[top--];

    }

    int peek(){
        if(isEmpty()){
            cout << "Empty stack with top as ";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }
};

int main(){

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.pop() << '\n';
    cout << st.peek() << '\n';
    cout << st.pop() << '\n';
    cout << st.peek() << '\n';
    cout << st.pop() << '\n';
    cout << st.peek() << '\n';
    cout << st.pop() << '\n';
    cout << st.peek() << '\n';
    
}