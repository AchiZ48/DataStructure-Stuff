#include <iostream>
#define SIZE 5
using namespace std;

class Queue{
    int front = 0;
    int rear = -1;
    int arr[SIZE];
    int count = 0;
public:
    bool isFull() { return count == SIZE; }
    bool isEmpty() { return count == 0; }
    void enqueue(int x){
        if(!isFull()){
            rear = (rear+1) % SIZE;
            arr[rear] = x;
            count++;
        }
        else cout<<"Queue Full"<<endl;
    }
    void dequeue(){
        if(!isEmpty()){
            front = (front+1) % SIZE;
            count--;
        }
        else cout<<"Queue Empty"<<endl;
    }

    void printQueue(){
        cout<<"f : "<<front<<" r : "<<rear<<endl;
    }
};

int main(){
    Queue q;
    char cmd;
    while(true){
        cin>>cmd;
        if(cmd == 'e'){
            int value;
            cin>>value;
            q.enqueue(value);
            q.printQueue();
        }
        if(cmd == 'd'){
            q.dequeue();
            q.printQueue();
        }
        if(cmd == 'x') break;
    }
}