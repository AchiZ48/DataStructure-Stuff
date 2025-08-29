#include<iostream>
#define SIZE 100

using namespace std;

class stack{
    int arr[SIZE];
    int top = 0;
public:
    bool isEmpty(){
        return top == 0;
    }
    bool isFull(){
        return top == SIZE;
    }
    char peek(){
        if(!isEmpty()) return arr[top-1];
    }
    void push(int data){
        if(!isFull()){
            arr[top] = data;
            top++;
        }
    }
    void pop(){
        if(!isEmpty()){
            top--;
        }
    }

};

int main(){
    stack s;
    char x;
    bool match = true;
    int n = 0;
    while(cin.get(x) && x != '\n' && match == true) {
        switch (x)
        {
        case '\n':
            return 0;
        case '(':
        case '[':
        case '{':
            s.push(x);
            break;
        case '<':
            if(!s.isEmpty() && s.peek() == '<'){
                s.pop();
            }
            else {
                s.push('<');
            }
            break;
        case ')':
            if(!s.isEmpty() && s.peek() == '('){
                s.pop();
                n++;
            }
            else match = false;
            break;
        case ']':
            if(!s.isEmpty() && s.peek() == '['){
                s.pop();
                n++;
            }
            else match = false;
            break;
        case '}':
            if(!s.isEmpty() && s.peek() == '{'){
                s.pop();
                n++;
            }
            else match = false;
            break;
        case '>':
            if(!s.isEmpty() && s.peek() == '<'){
                s.pop();
                n++;
            }
            else match = false;
            break;
        
        }
    }
    if (!s.isEmpty()) match = false;
    if(match == true){
        cout<<n<<" matched"<<endl;
    }
    else if(match == false){
        cout<<"Not matched"<<endl;
        cout<<n<<" matched"<<endl;
    }
}