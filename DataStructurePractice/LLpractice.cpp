#include<iostream>
using namespace std;
struct Node{
    int value;
    Node *next;
    Node(int v){
        value = v;
        next = nullptr;
    }
};
class LL{
    public:
    Node *head;
    LL(){
        head = nullptr;
    }
    void insBefore(int pos, int val){
        Node *temp = new Node(val);
        Node *curr = head;
        if (head == nullptr){
            head = temp;
            return;
        }
        if (head->value == pos){
            temp->next = head;
            head = temp;
            return;
        }
        while(curr->next != nullptr && curr->next->value != pos){
            curr = curr->next;
        } 
        temp->next = curr->next;
        curr->next = temp;
    }
    void insAfter(int pos, int val){
        Node *temp = new Node(val);
        Node *curr = head;
        if(head == nullptr){
            head = temp;
            return;
        }
        while(curr->next != nullptr && curr->value != pos){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
    void deleteNode(int pos){
        if(head == nullptr) return;
        if(head->value == pos){
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *curr = head;
        while(curr->next != nullptr && curr->next->value != pos){
            curr = curr->next;
        }
        if(curr->next != nullptr){
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
    void printList(){
        Node *curr = head;
        while(curr != nullptr){
            cout<<curr->value<<" ";
            curr = curr->next;
        }
    }
};
int main(){
    LL a;
    char cmd;
    while (true) {
        cin >> cmd;
        if (cmd == 'b') {
            int position, value;
            cin >> position >> value;
            a.insBefore(position, value);
            a.printList();
            cout << endl;
        } else if (cmd == 'a') {
            int position, value;
            cin >> position >> value;
            a.insAfter(position, value);
            a.printList();
            cout << endl;
        } else if (cmd == 'd') {
            int value;
            cin >> value;
            a.deleteNode(value);
            a.printList();
            cout << endl;
        } else if (cmd == 'x') {
            break;
        }
    }    
}