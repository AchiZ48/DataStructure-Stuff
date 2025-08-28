#include <iostream>

#define SIZE 6

using namespace std;

class ArrayQueue {
    int arr[SIZE];
    int front = 2, rear = 1;
    int count = 0;
public:
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == SIZE-1;
    }
    void enqueue(int x){
        if(isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        else {
            rear = (rear + 1) % SIZE;
            arr[rear] = x;
            cout << "f:" << front << " r:" << rear << endl;
            count++;
        }
    }

    int size(){
        return count;
        }

    void dequeue(){
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << arr[front] << endl;
        front = (front + 1) % SIZE;
        cout << "f:" << front << " r:" << rear << endl;
        count--;
    }
    int peek()
    {
        if (this->isEmpty()) {
            printf("Queue is Empty!\n");
            return -1;
        }
        return arr[(front + 1) % SIZE];
    }
    void print()
    {
        if (this->isEmpty())
            return;
        for (int i = (front + 1) % SIZE; i != (rear + 1) % SIZE;
             i = (i + 1) % SIZE) {

            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue q;
    char cmd;
    while (true) {
        cin >> cmd;
        if(cmd == 'e'){
            int value;
            cin >> value;
            q.enqueue(value);
        }
        else if(cmd == 'd'){
            q.dequeue();
        }
        else if(cmd == 'p'){
            q.print();
        }
        else if(cmd == 'x'){
            break;
        }
    }

    return 0;
}