#include <iostream>
using namespace std;
const int N = 1000;

class Queue{

    int arr[N];
    int start, end, currSize;

public:
    Queue(){
        start = -1;
        end = -1;
        currSize = 0;
    }


    void push(int x){

        if(currSize == N){
            cout << "Queue is full!" << '\n';
            exit(1);
        }

        if(end == -1){
            start = 0;
            end = 0;
            arr[end] = x;
        }

        else{
            end = (end+1)%N;
            arr[end] = x;

        }

        currSize++;

    }

    int pop(){

        if(currSize == 0){
            cout << "Queue is empty!" << '\n';
            exit(1);
        }

        int x = arr[start];

        if(currSize == 1){
            start = -1;
            end = -1;
        }
        else{
            start = (start+1)%N;
        }

        currSize--;
        return x;
    }

    int front(){
        if(currSize == 0){
            cout << "Queue is empty!" << '\n';
            exit(1);
        }

        return arr[start];
    }

    int size(){
        return currSize;
    }

};


int main(){

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

   
    cout << q.size() << '\n';
    cout << q.front() << '\n';

    q.pop();

    cout << q.size() << '\n';
    cout << q.front() << '\n';
}