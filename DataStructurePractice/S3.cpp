#include<iostream>
#define SIZE 5
using namespace std;

class Queue{
    int front = 2;
    int rear = 1;
    int arr[SIZE];
    int size = 0;
public:
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == SIZE;
    }
    void enqueue(int data){
        if(!isFull()){
            rear = (rear + 1) % SIZE;
            arr[rear] = data;
            printQueue();
            size++;
        }
        else if(isFull()){
            cout<<"Queue Full ";
            printQueue();
        }
    }
    void dequeue(){
        if(!isEmpty()){
            cout<<arr[front]<<" ";
            front = (front + 1 ) % SIZE;
            printQueue();
            size--;
        }
        else if(isEmpty()){
            cout<<"Queue Empty ";
            printQueue();
        }
    }
    void printQueue(){
        cout<<"f:"<<front<<" r:"<<rear<<endl;
        
    }

};



int main(){
    Queue q;
    char cmd;
    while(cin>>cmd){
        if(cmd == 'e'){
            int input;
            cin>>input;
            q.enqueue(input);
        }
        else if(cmd == 'd'){
            q.dequeue();
        }
        else if(cmd == 'x'){
            break;
        }
    }
}
