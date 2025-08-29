#include<iostream>
#define SIZE 100

using namespace std;

class stack{
    char arr[SIZE];
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
        return '\0';
    }
    void push(char data){
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
    string str;
    getline(cin, str);
    bool match = true;
    int n = 0;
    for(int i = 0; i < str.size(); i++){
        char x = str[i];
        switch (x){
        case '(':
        case '[':
        case '{':
            s.push(x);
            break;
        case '<':
            if(i + 1 < str.size() && str[i+1] == '<'){
                i++;
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
            if(i + 1 < str.size() && str[i+1] == '>'){
                i++;
            }
            else{
                if(!s.isEmpty() && s.peek() == '<'){
                    s.pop();
                    n++;
                }
                else match = false;  
            }      
            break;
        }
        if (!match) break;
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